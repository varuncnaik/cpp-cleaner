#!/bin/bash

main() {
    local actual=$(python cleanup.py < input0.cpp 2> /dev/null)
    if (($? != 0)); then
        echo "Test 0 crashed"
        return 1
    fi
    local expected=$(cat output0.cpp)
    if [[ "$actual" != "$expected" ]]; then
        echo "Test 0 failed"
        return 1
    fi
    echo "Test 0 passed"
}

main "$@"
