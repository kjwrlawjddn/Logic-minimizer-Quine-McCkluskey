디지털 공학을 배운 사람이라면 논리회로설계에서 논리최소화가 중요하다는 것을 알고 있을 것입니다. 하지만 변수의 개수가 4개를 초과하게 된다면, 사람이 손으로 논리최소화를 하기에는 어려움이 있을 것입니다. 10변수까지 논리최소화를 할 수 있는 logic minimizer라는 프로그램이 있기는 하지만, minterm과 don't care항이 많아지는 순간 프로그램은 멈추게 되는 불안정한 프로그램입니다.

한편 논리최소화를 할 수 있는 방법 중에는 카르노맵 뿐 아니라 Quine McCluskey 알고리즘이나 ESPRESSO 알고리즘이 있습니다. Quine McCluskey 알고리즘은 4변수 이상에서 사용하는 매우 정확한 방법으로 변수의 개수가 적당히 많을 때 사용하기 좋은 방법입니다. 하지만 변수의 개수가 증가함에 따라 계산과정은 기하급수적으로 많아지게 됩니다. 따라서 요즘은 근사해를 찾는 ESPRESSO 알고리즘을 사용합니다. git hub에 Quine McCluskey 알고리즘을 C++로 구현해본 사람은 많았지만, 제대로 논리최소화가 되게끔 설계한 사람은 없었습니다. 따라서 저는 Quine McCluskey 알고리즘을 C++로 구현하여 계산량을 최소화해보았습니다.

이 프로그램의 관건은 Implicant들을 빠르게 찾아내는 것입니다. 예를 들어 사람은 0001과 1001은 가장 앞 비트만 다르다는 것을 단번에 알 수 있지만, 컴퓨터는 그렇지 않습니다. 예시의 결과를 도출하기 위해서는, 적어도 4번의 비트별 연산이 필요합니다. 이대로 프로그램을 작성한다면 4번의 연산을 위해 수반되는 추가적인 메모리 또한 증가할 것입니다. 연산 횟수를 줄이기 위해, 거의 모든 연산을 비트연산으로 바꾸어 1번의 연산만으로도 위 예시의 결과를 도출 할 수 있게 코드를 작성했습니다.

이 프로그램은 10변수 이상에서도 컴퓨터의 메모리가 허용하는 한 제한없이 논리최소화를 할 수 있습니다. 대학교 수준의 논리최소화에서 유용하게 사용할 수 있을 것입니다.
궁금하신 점이 있다면 아래의 메일로 연락 바랍니다. 

Anyone who has studied digital logic circuits knows that logic minimization is important for logic circuit design.However, if there are more than four variables, it is difficult to minimize them by hand, and you have to use other algorithms. The Quine McCluskey algorithm is one of them, and I've implemented it in C++.

The key to this project was to create an efficient program by minimizing computational time that increases exponentially as variables increase. Therefore, most operations were replaced by bit operations.

It will be quite helpful when designing a logic device at the university level.

If you have any question, please send e-mail to kjw0103501@kw.ac.kr or kjwrlawjddn@naver.com or kjw0103501@gmail.com(not recommended)

광운대학교 김정우
Jungwoo Kim, Kwangwoon University
