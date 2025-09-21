#!/usr/bin/env bash
# RPN test runner for CPP Module 09 — ex01
# All expected outputs are either an integer or the exact string "Error".

set -u

BIN="./RPN"

pass=0
fail=0

run() {
  local expr="$1"
  local expected="$2"
  local out
  out="$($BIN "$expr" 2>&1 | tr -d '\r')"
  if [[ "$out" == "$expected" ]]; then
    printf "PASS  | %-70s -> %s\n" "$expr" "$out"
    ((pass++))
  else
    printf "FAIL  | %-70s -> got: %-12s expected: %s\n" "$expr" "$out" "$expected"
    ((fail++))
  fi
}

echo "== Basic correct expressions =="
run "3 4 +"                     "7"
run "5"                         "5"
run "3 4 + 2 * 7 /"             "2"
run "9 5 - 2 /"                 "2"
run "5 8 - 2 /"                 "-1"
run "2 3 * 4 +"                 "10"
run "3    4      +"             "7"
run $'3\t4\t+'                  "7"

echo
echo "== Errors: format / operands / division =="
run "3 +"                       "Error"    # not enough operands
run "+"                         "Error"    # not enough operands
run "2 2 2 +"                   "Error"    # extra operand at end
run "10 2 +"                    "Error"    # multi-digit not allowed
run "3 a +"                     "Error"    # invalid token
run "3 4+"                      "Error"    # missing space
run ""                          "Error"    # empty input
run "4 0 /"                     "Error"    # division by zero

echo
echo "== Overflow checks =="
# 9^9 fits in int, 9^10 overflows
run "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"               "387420489"
run "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"           "Error"

echo
echo "== INT_MAX + 1 (build INT_MAX via base-10, then +1) =="
# Build INT_MAX (2147483647) using: x = x*10 + d, with 10 = (9 1 +)
# Pattern: start 0, then for each digit d: "9 1 + * d +"
# Finally: "1 +" to trigger overflow.
expr_intmax_build="0 \
  9 1 + * 2 + \
  9 1 + * 1 + \
  9 1 + * 4 + \
  9 1 + * 7 + \
  9 1 + * 4 + \
  9 1 + * 8 + \
  9 1 + * 3 + \
  9 1 + * 6 + \
  9 1 + * 4 + \
  9 1 + * 7 +"
run "$expr_intmax_build 1 +"    "Error"   # INT_MAX + 1 -> overflow

# (Optional sanity) If you want to see INT_MAX itself (not part of subject), uncomment:
# run "$expr_intmax_build"        "2147483647"

echo
echo "== INT_MIN - 1 (build 1073741824 via base-10, negate, *2 => INT_MIN, then -1) =="
# Build 1073741824 as above while preserving a leading 0 under it to negate: result stack [0, X]
# Then: "-" -> 0 - X = -1073741824
# Then: "2 *" -> -2147483648 (INT_MIN)
# Then: "1 -" -> INT_MIN - 1 -> overflow
expr_intmin_minus1="0 0 \
  9 1 + * 1 + \
  9 1 + * 0 + \
  9 1 + * 7 + \
  9 1 + * 3 + \
  9 1 + * 7 + \
  9 1 + * 4 + \
  9 1 + * 1 + \
  9 1 + * 8 + \
  9 1 + * 2 + \
  9 1 + * 4 + \
  - 2 * 1 -"
run "$expr_intmin_minus1"       "Error"   # INT_MIN - 1 -> overflow

echo
echo "== Summary =="
echo "Passed: $pass"
echo "Failed: $fail"
exit $(( fail > 0 ))
