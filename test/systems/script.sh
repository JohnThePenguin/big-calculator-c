# /bin/bash

ls tmp && rm -rf tmp
mkdir tmp
touch tmp/input.txt
touch tmp/output.txt
touch tmp/expected.txt

BINEARY_PATH="./../../build/main"

if [ ! -f $BINEARY_PATH ]; then
    echo "Binary not found! Compile the project first."
    exit 1
fi

i=0

while true; do
    i=$((i+1))

    python3 generate.py > tmp/input.txt
    python3 solution.py < tmp/input.txt > tmp/expected.txt
    $BINEARY_PATH < tmp/input.txt > tmp/output.txt

    if ! diff tmp/output.txt tmp/expected.txt -b; then
        echo "$i: Test failed !!!"
        break
    else
        echo "$i: Test passed"
    fi
done

cd ..