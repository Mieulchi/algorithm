# [Gold II] 거듭제곱 계산 - 3910 

[문제 링크](https://www.acmicpc.net/problem/3910) 

### 성능 요약

메모리: 2028 KB, 시간: 152 ms

### 분류

그래프 이론, 그래프 탐색, 백트래킹, 런타임 전의 전처리

### 제출 일자

2026년 04월 05일 22:41:46

### 문제 설명

<p>x에 x를 30번 곱하면 x<sup>31</sup>이 된다.</p>

<p>x<sup>2</sup> = x × x, x<sup>3</sup> = x<sup>2</sup> × x, x<sup>4</sup> = x<sup>3</sup> × x, ..., x<sup>31</sup> = x<sup>30</sup> × x</p>

<p>만약, 결과를 제곱할 수 있다면, 8번만에 x<sup>31</sup>을 구할 수 있다.</p>

<p>x<sup>2</sup> = x × x, x<sup>3</sup> = x<sup>2</sup> × x, x<sup>6</sup> = x<sup>3</sup> × x<sup>3</sup>, x<sup>7</sup> = x<sup>6</sup> × x, x<sup>14</sup> = x<sup>7</sup> × x<sup>7</sup>, x<sup>15</sup> = x<sup>14</sup> × x, x<sup>30</sup> = x<sup>15</sup> × x<sup>15</sup>, x<sup>31</sup> = x<sup>30</sup> × x</p>

<p>이전에 나온 계산 결과를 곱하는 방법도 같이 사용한다면 x<sup>31</sup>은 7번만에 구할 수 있다.</p>

<p>x<sup>2</sup> = x × x, x<sup>4</sup> = x<sup>2</sup> × x<sup>2</sup>, x<sup>8</sup> = x<sup>4</sup> × x<sup>4</sup>, x<sup>10</sup> = x<sup>8</sup> × x<sup>2</sup>, x<sup>20</sup> = x<sup>10</sup> × x<sup>10</sup>, x<sup>30</sup> = x<sup>20</sup> × x<sup>10</sup>, x<sup>31</sup> = x<sup>30</sup> × x</p>

<p>위의 방법이 곱셈만으로 x<sup>31</sup>을 구하는 가장 효율적인 방법이다.</p>

<p>만약 나눗셈을 사용할 수 있다면, 연산의 수를 더 줄일 수 있다. x<sup>31</sup>을 5번의 곱셈과 1번의 나눗셈으로 구할 수 있다.</p>

<p>x<sup>2</sup> = x × x, x<sup>4</sup> = x<sup>2</sup> × x<sup>2</sup>, x<sup>8</sup> = x<sup>4</sup> × x<sup>4</sup>, x<sup>16</sup> = x<sup>8</sup> × x<sup>8</sup>, x<sup>32</sup> = x<sup>16</sup> × x<sup>16</sup>, x<sup>31</sup> = x<sup>32 </sup>÷ x</p>

<p>이 방법은 나눗셈이 곱셈만큼 빠를 때 x<sup>31</sup>을 계산하는 가장 효율적인 방법이다.</p>

<p>x로 시작해서 x<sup>n</sup>을 만드는데 드는 연산 회수의 최솟값을 구하는 프로그램을 작성하시오. 문제에서 설명한 곱셈과 나눗셈만 사용할 수 있다. 연산의 결과는 항상 x의 양의 제곱수 이어야 한다. 즉, x<sup>-3</sup>은 나오면 안 된다.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 구성되어 있고, 정수 n이 주어진다. n은 양의 정수이며, 1000보다 작거나 같다.</p>

### 출력 

 <p>각각의 테스트 케이스에 대해서, 한 줄에 하나씩 x<sup>n</sup>을 만드는데 필요한 곱셈과 나눗셈의 최소 회수를 출력한다.</p>

