#!/usr/bin/python
#
# Sources:
# http://en.cppreference.com/w/cpp/language/string_literal
# http://en.cppreference.com/w/cpp/language/translation_phases

import re
import sys

def replace_contents(s):
    def repl(match):
        if match.group(1) is not None:
            assert isinstance(match.group(1), str)
            return match.group(1)
        return "x"
    pattern = re.compile(
        r"("
            r"\\[ \t\v\f\r]*(?=\n)"              # Backslash + whitespace, followed by newline
            r"|(?<=\n)[ \t\v\f\r]+"              # Preceded by newline, whitespace
            r"|\n"                               # Newline
        r")|.",
        re.DOTALL | re.MULTILINE
    )
    return re.sub(pattern, repl, s)

def replace_raw_string_contents(s):
    def repl(match):
        if match.group(1) is not None:
            assert isinstance(match.group(1), str)
            return match.group(1)
        return "x"
    pattern = re.compile(
        r"("
            r"(?<=\n)[ \t\v\f\r]+"               # Preceded by newline, whitespace
            r"|\n"                               # Newline
        r")|.",
        re.DOTALL | re.MULTILINE
    )
    delimiter_length = s.find("(")
    raw_characters = s[delimiter_length+1:-delimiter_length-1]
    new_delimiter = "x"*delimiter_length
    new_raw_characters = re.sub(pattern, repl, raw_characters)
    return "{}({}){}".format(new_delimiter, new_raw_characters, new_delimiter)

def cleanup(text):
    def repl(match):
        s = match.group(0)
        if match.group(1) is not None:
            return match.group(1) + replace_contents(match.group(2)) + match.group(3)
        if match.group(4) is not None:
            return match.group(4) + replace_contents(match.group(5))
        if match.group(6) is not None:
            return match.group(6) + replace_raw_string_contents(match.group(7)) + match.group(9)
        if match.group(10) is not None:
            return match.group(10) + replace_contents(match.group(11)) + match.group(12)
        if match.group(13) is not None:
            return match.group(13) + replace_contents(match.group(14)) + match.group(15)
        raise Exception
    # Backslash + whitespace + newline continues a string, comment, etc. onto the next line.
    # The C++ standard only specifies that backslash + newline are removed to form a single logical
    # line, but g++ and clang also perform this behavior if there is whitespace after the
    # backslash. Similarly, the basic source character set in C++
    # (http://en.cppreference.com/w/cpp/language/translation_phases) does not contain carriage
    # return, but g++ and clang treat carriage return as whitespace.
    cont = r"(?:\\[ \t\v\f\r]*\n)"               # Backslash magic to continue to next line
    pattern = re.compile(
        r"(/{cont}*\*)(.*?)(\*{cont}*/)"         # Block comment
        r"|(/{cont}*/)((?:{cont}|.)*?)$"         # End-of-line comment
        r'|(R{cont}*")(([^()\\ ]*)\(.*?\)\8)(")' # Raw string literal
        r'|(")((?:\\.|[^"])*)(")'                # String literal
        r"|(')((?:\\.|[^'])*)(')"                # Character literal
        .format(cont=cont),
        re.DOTALL | re.MULTILINE
    )
    return re.sub(pattern, repl, text)

def main():
    contents = sys.stdin.read().replace("\r\n", "\n")
    cleaned = cleanup(contents)
    sys.stdout.write(cleaned)

if __name__ == "__main__":
    main()
