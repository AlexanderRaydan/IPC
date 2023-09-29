filename=$1

gcc -Wall $filename -o output
./output
rm output