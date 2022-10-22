/* 
Submitted by: Sneha Jaiswal
GitHub link: https://github.com/Sneha-jais
Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.
Input Format :
Line 1 : Input String S
Line 2 : Character c1 and c2 (separated by space)

Output Format :
Updated string

Constraints :
1 <= Length of String S <= 10^6

Sample Input :
abacd
a x

Sample Output :
xbxcd
*/


#include<iostream>
using namespace std;

void replace_char(char s[],char a,char b){

if(s[0]=='\0')
    return ;
if(s[0]==a){
    s[0]=b;
}

    replace_char(s+1,a,b);

}

int main(){

char s[100];
cin>>s;
char c1,c2;

cin>>c1>>c2;

replace_char(s,c1,c2);

cout<<s<<" ";

    return 0;
}
