#!/bin/bash

rm -f sol*.exe
rm -f gen*.exe

g++ -std=c++11 -O2 -o gen_sample.exe gen_sample.cpp
g++ -std=c++11 -O2 -o gen_small.exe gen_small.cpp
g++ -std=c++11 -O2 -o gen_medium.exe gen_medium.cpp
g++ -std=c++11 -O2 -o gen_random.exe gen_random.cpp
g++ -std=c++11 -O2 -o gen_big.exe gen_big.cpp
g++ -std=c++11 -O2 -o sol.exe sol.cpp

rm -rf Input
rm -rf Output

mkdir Input
mkdir Output

./gen_sample.exe "./Input/input1.txt"
./gen_sample.exe "./Input/input2.txt"
./gen_small.exe "./Input/input3.txt"
./gen_small.exe "./Input/input4.txt"
./gen_medium.exe "./Input/input5.txt"
./gen_medium.exe "./Input/input6.txt"
./gen_big.exe "./Input/input7.txt"
./gen_big.exe "./Input/input8.txt"
./gen_big.exe "./Input/input9.txt"
./gen_random.exe "./Input/input10.txt"

./sol.exe < "./Input/input1.txt" > "./Output/output1.txt"
./sol.exe < "./Input/input2.txt" > "./Output/output2.txt"
./sol.exe < "./Input/input3.txt" > "./Output/output3.txt"
./sol.exe < "./Input/input4.txt" > "./Output/output4.txt"
./sol.exe < "./Input/input5.txt" > "./Output/output5.txt"
./sol.exe < "./Input/input6.txt" > "./Output/output6.txt"
./sol.exe < "./Input/input7.txt" > "./Output/output7.txt"
./sol.exe < "./Input/input8.txt" > "./Output/output8.txt"
./sol.exe < "./Input/input9.txt" > "./Output/output9.txt"
./sol.exe < "./Input/input10.txt" > "./Output/output10.txt"

rm -rf sol*.exe
rm -f gen*.exe

zip testcase.zip Input/* Output/* Config.json
echo testcase zipped

echo "# **Sample Input**" > sample.md
echo "\`\`\`" >> sample.md
cat Input/input1.txt >> sample.md
echo "\`\`\`" >> sample.md
echo "\`\`\`" >> sample.md
cat Input/input2.txt >> sample.md
echo "\`\`\`" >> sample.md

echo "" >> sample.md
echo "# **Sample Output**" >> sample.md
echo "\`\`\`" >> sample.md
cat Output/output1.txt >> sample.md
echo "\`\`\`" >> sample.md
echo "\`\`\`" >> sample.md
cat Output/output2.txt >> sample.md
echo "\`\`\`" >> sample.md

