디지털 논리를 배운 사람이라면 카르노 맵을 이용해 논리최소화를 할 수 있다는 것쯤은 알고 있을 것입니다. 하지만 변수가 4개를 초과하게 된다면 사람 손으로 하기에는 힘이 들고, 다른 방법이나 프로그램을 이용하려 할 것입니다. 10변수 까지 논리최소화를 해주는 logic minimizer라는 프로그램이 있기는 하지만, minterm들이 다양해지는 순간 프로그램은 멈추곤 하여 쓰기가 곤란합니다.

논리최소화를 할 수 있는 방법 중에는 카르노 맵뿐 아니라 Quine McCluskey 알고리즘이 있습니다. (원리 자체는 카르노 맵과 동일합니다.) 따라서 c++을 이용해 Quine McCluskey 알고리즘을 구현해 보았습니다.

Quine McCluskey 알고리즘의 핵심은 Implicant들을 찾아내는 것입니다. 예를 들어 0001과 1001은 가장 앞 비트만 다르므로 이 단계에서는 -001이 됩니다. 사람이라면 무엇이 어디가 다른지 금방 알 수 있지만, 컴퓨터는 그렇지 않습니다. 예시의 결과를 도출하기 위해서는, 적어도 4번의 연산이 필요합니다. 4번의 연산을 위해 수반되는 추가적인 메모리 또한 증가할 것입니다. 연산 횟수를 줄이기 위해, 모든 연산을 비트연산으로 적용해 1번의 연산만으로도 위 예시의 결과를 도출 할 수 있게 코드를 작성했습니다.

대학교 수준의 논리최소화에서 유용하게 사용할 수 있을 것입니다.

궁금하신 점이 있다면 아래의 메일로 연락 바랍니다. 광운대학교, 김정우

Anyone who has studied digital logic circuits knows that logic minimization is important for logic circuit design.

However, if there are more than four variables, it is difficult to minimize them by hand, and you have to use other algorithms.

The Quine McCluskey algorithm is one of them, and I've implemented it in C++.

The key to this project was to create an efficient program by minimizing computational time that increases exponentially as variables increase.

Therefore, most operations were replaced by bit operations.

It will be quite helpful when designing a logic device at the university level.

If you have any question, please send e-mail to kjw0103501@kw.ac.kr or kjwrlawjddn@naver.com or kjw0103501@gmail.com(not recommended)

Kwangwoon University, Jungwoo Kim, junior
