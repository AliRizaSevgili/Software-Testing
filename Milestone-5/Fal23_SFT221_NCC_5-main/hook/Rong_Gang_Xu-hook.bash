#!/bin/sh 

echo "Starting test runner..." 

test_runner="C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\Extensions\TestPlatform"

tests_dll="project-sourcecode\project-starter\whitebox-test.dll" 

failure_string="Failed:" 

testout=`"$test_runner" "$tests_dll"` 

if [[ $testout == *"$failure_string"* ]]; then 

echo >&2 "Unit test are not passing! Push aborted!" 

exit 1 

fi 
