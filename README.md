//////////////////////////////////////////////////////////////////\
다운로드 및 사용법 || How to download and use\
[여기를 클릭하시면 프로그램 파일과 사용법을 확인할 수 있습니다.](https://github.com/HigherIdeal/Logic-minimizer-Quine-McCkluskey/releases)\
[If you click this, you can check the file and how to use it.](https://github.com/HigherIdeal/Logic-minimizer-Quine-McCkluskey/releases)\
//////////////////////////////////////////////////////////////////

디지털 공학을 배웠다면, 논리회로설계에서 논리최소화 단계가 중요하다는 것을 알고 있을 것입니다. 4변수 이하의 논리최소화는 Karnaugh map을 이용해 손으로도 가능하지만, 5변수 이상의 논리최소화는 컴퓨터의 도움을 받아야 합니다. 

논리최소화 방법은 이미 옛날부터 사용해온 Quine McCluskey 알고리즘이나 ESPRESSO 알고리즘이 있습니다. 요즘엔 근사해를 찾는 방식인 ESPRESSO 알고리즘을 많이 사용하기는 합니다. 하지만 저는, 더 정석적인 방법을 사용하는 Quine McCluskey 알고리즘을 선택했습니다.

git hub에 Quine McCluskey 알고리즘을 C++로 만드려는 사람이 몇 있었지만 오류 투성이라 제가 제대로 한번 만들어 보게 되었습니다. 

Quine McCluskey 알고리즘의 치명적인 단점은 변수가 많아질수록 계산량이 기하급수적으로 늘어난다는 점입니다. 가령 5변수의 minterm 중 두 개의 2진수 10011과 10010을 비교할 때, 사람은 LSB만 다르다는 것을 단번에 알 수 있지만, 컴퓨터는 각 자리별로 비트연산을 하여 총 5번의 연산끝에 LSB가 다르다는 점을 알아내게 됩니다. 만약 2개의 10변수의 minterm 중 두 개의 2진수 1000101000과 1000101001을 비교하게 된다면 연산량이 점점 증가하는 것을 이해할 수 있을 것입니다. if문을 이용해 분기를 나누게 되면 연산이 매우 오래 걸리게 되기 때문에, 최대한 빠르게 계산하고자 minterm들을 10진수의 비트연산으로 바꾸어 최대한 속도를 빠르게 만들었습니다.

이 프로그램은 14변수 이상에서도 컴퓨터의 메모리가 허용하는 한 변수의 개수 제한없이 논리최소화를 할 수 있습니다. 학부 수준의 논리최소화에서 유용하게 사용할 수 있을 것입니다.
궁금하신 점이 있다면 아래의 메일로 연락 바랍니다. 



If you have studied digital engineering, you know that the logic minimization step is important in logic circuit design. Logical minimization of 4 variables or less can be done by hand using a Karnaugh map, but logic minimization of 5 variables or more requires computer help.

Logic minimization methods include the Quine McCluskey algorithm and the ESPRESSO algorithm, which have been used for a long time. Nowadays, the ESPRESSO algorithm, which is a method for finding approximate solutions, is widely used. However, I chose the Quine McCluskey algorithm, which uses a more canonical method.

There were several people on the git hub who tried to make the Quine McCluskey algorithm in C++, but it was full of errors, so I decided to make it properly.

The fatal disadvantage of the Quine McCluskey algorithm is that the amount of computation increases exponentially as the number of variables increases. For example, when comparing two binary numbers 10011 and 10010 among 5 variable minterms, a person can know at once that only the LSB is different, whereas a computer performs bitwise operation for each digit and finds out that the LSB is different after a total of 5 operations . If you compare two binary numbers 1000101000 and 1000101001 of two 10-variable minterms, you will understand that the amount of operation increases exponentially. To overcome this shortcoming, minterms were replaced with decimal bit operations in most calculations to speed up as much as possible.

Even with 14 or more variables, this program can perform logic minimization without limiting the number of variables as long as the computer memory allows. It will be useful for logic minimization at the undergraduate level.
If you have any question, please send e-mail to kjw0103501@kw.ac.kr or kjwrlawjddn@naver.com or kjw0103501@gmail.com(not recommended)

광운대학교 김정우
Jungwoo Kim, Kwangwoon University
