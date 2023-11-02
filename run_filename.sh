filename=$1

rm -f output

gcc -Wall $filename -o output
./output
rm output