set -o pipefail
for input in cases/*.in; do
  if ./scores < "$input" | tr -d '\r' |
     diff -u "${input%.in}.out" - >/dev/null; then
    echo "PASS $input"
  else
    echo "FAIL $input"
  fi
done