#!/bin/bash
workshopNumber=$1
part=$2

dir=`pwd`

osascript -e 'tell app "Terminal"
   do script "cd '$dir' ; sh run.sh '$workshopNumber' '$part'"
end tell'