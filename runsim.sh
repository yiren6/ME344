#!/bin/bash -l
# move to testcase

cd /usr/local/testCase
source /.bashrc
python3 su2_and_Tetgen_PyTest.py

echo "-----------------------------"
echo "|||  TestCase completed!  |||"
echo "-----------------------------"

# move data to shared drive
cd /usr/local
source /.bashrc
mv testCase/ IO/
echo "*******Completed, quit*********"
exit
