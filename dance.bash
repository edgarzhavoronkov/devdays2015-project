#1/bin/bash

path="/dev/"
device=$(ls /dev | grep USB)
devicePath=$path$device

echo "3" > $devicePath
echo "6 30" > $devicePath
echo "4 0" > $devicePath
echo "5 0" > $devicePath
echo "7 0" > $devicePath

sleep 8.5
echo "6 90" > $devicePath
sleep 1

echo "2" > $devicePath
sleep 0.5
echo "3" > $devicePath
sleep 0.5
echo "2" > $devicePath
sleep 0.5
echo "3" > $devicePath
sleep 0.7

echo "2" > $devicePath
sleep 0.5
echo "3" > $devicePath
sleep 0.5
echo "2" > $devicePath
sleep 0.5
echo "3" > $devicePath
sleep 0.7


echo "1" > $devicePath
sleep 2

echo "4 160" > $devicePath
echo "7 200" > $devicePath
sleep 1.5

echo "4 0" > $devicePath
echo "5 160" > $devicePath
echo "7 0" > $devicePath
sleep 1.5

echo "4 90" > $devicePath
echo "5 90" > $devicePath
sleep 3



echo "4 120" > $devicePath
echo "5 60" > $devicePath
echo "7 50" > $devicePath
sleep 0.5


echo "4 60" > $devicePath
echo "5 120" > $devicePath
echo "7 0" > $devicePath
sleep 0.5

echo "4 120" > $devicePath
echo "5 60" > $devicePath
echo "7 50" > $devicePath
sleep 0.5

echo "4 60" > $devicePath
echo "5 120" > $devicePath
echo "7 0" > $devicePath
sleep 0.5

echo "4 120" > $devicePath
echo "5 60" > $devicePath
echo "7 50" > $devicePath
sleep 0.5

echo "4 60" > $devicePath
echo "5 120" > $devicePath
echo "7 0" > $devicePath
sleep 0.5

echo "4 120" > $devicePath
echo "5 60" > $devicePath
echo "7 50" > $devicePath
sleep 0.5

echo "4 60" > $devicePath
echo "5 120" > $devicePath
echo "7 0" > $devicePath
sleep 0.5

echo "4 120" > $devicePath
echo "5 60" > $devicePath
echo "7 50" > $devicePath
sleep 0.5

echo "4 60" > $devicePath
echo "5 120" > $devicePath
echo "7 0" > $devicePath
sleep 0.5



echo "4 60" > $devicePath
echo "5 120" > $devicePath
echo "7 0" > $devicePath
echo "6 60" > $devicePath
sleep 0.5

echo "4 120" > $devicePath
echo "5 60" > $devicePath
echo "7 50" > $devicePath
echo "6 120" > $devicePath
sleep 0.5

echo "4 60" > $devicePath
echo "5 120" > $devicePath
echo "7 0" > $devicePath
echo "6 60" > $devicePath
sleep 0.5

echo "4 120" > $devicePath
echo "5 60" > $devicePath
echo "7 50" > $devicePath
echo "6 120" > $devicePath
sleep 0.5


echo "4 60" > $devicePath
echo "5 120" > $devicePath
echo "7 0" > $devicePath
echo "6 60" > $devicePath
sleep 0.5

echo "4 120" > $devicePath
echo "5 60" > $devicePath
echo "7 50" > $devicePath
echo "6 120" > $devicePath
sleep 0.5


echo "4 60" > $devicePath
echo "5 120" > $devicePath
echo "7 0" > $devicePath
echo "6 60" > $devicePath
sleep 0.5

echo "4 120" > $devicePath
echo "5 60" > $devicePath
echo "7 50" > $devicePath
echo "6 120" > $devicePath
sleep 0.5


echo "4 60" > $devicePath
echo "5 120" > $devicePath
echo "7 0" > $devicePath
echo "6 60" > $devicePath
sleep 0.5

echo "4 120" > $devicePath
echo "5 60" > $devicePath
echo "7 50" > $devicePath
echo "6 120" > $devicePath
sleep 4


echo "4 90" > $devicePath
echo "5 0" > $devicePath
echo "6 90" > $devicePath
sleep 2

echo "4 120" > $devicePath
sleep 0.5
echo "4 90" > $devicePath
sleep 0.5
echo "4 120" > $devicePath
sleep 0.5
echo "4 90" > $devicePath
sleep 0.5
echo "4 120" > $devicePath
sleep 0.5
echo "4 90" > $devicePath
sleep 0.5
echo "4 120" > $devicePath
sleep 0.5
echo "4 90" > $devicePath
sleep 0.5
echo "2" > $devicePath
sleep 2

echo "3" > $devicePath
echo "6 90" > $devicePath
echo "4 0" > $devicePath
echo "5 0" > $devicePath
echo "7 0" > $devicePath