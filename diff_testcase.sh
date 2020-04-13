#/bin/bash
fileName="$(basename $1)"
fileName=$(echo "$fileName" | cut -f 1 -d '.')
parentName="$(basename "$(dirname "${1}")")"
parentPath="$(cd $(dirname "$1") && pwd -P)"
echo $fileName
colordiff --side-by-side ${parentPath}/${fileName}.out ${parentPath}/${fileName}.ans
