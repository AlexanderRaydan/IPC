workshopNumber=$1
part=$2


dir=`pwd`
filename=${dir}/WS0${workshopNumber}/p${part}/w${workshopNumber}p${part}.c

echo filename: $filename

rm -f output

gcc -Wall $filename -o output
./output
rm output