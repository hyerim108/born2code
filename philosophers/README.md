# Description
> Eat, Sleep, Spaghetti, repeat. This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger.

### Data race
> 여러 스레드/ 프로세스가 공유자원에 동시에 접근하려 할때, 일어나는 경쟁상황
+ 한스레드와 또다른 스레드가 동시에 한 변수를 쓰려고 할 때, 한 스레드는 한 변수를 쓰고 있는데 다른스레드는 그 변수를 읽으려고 할때 당의 상황에서 발생한다.
아래는 간단한 예시
```
g_num = 0;

void    add(void)
{
  g_num++;
}
```
모든 쓰레드가 접근할 수 있는 g_num이 있고, add함수는 g_num을 1증가시킨다. 서로 다른 두 쓰레드가 add 함수를 호출한다면 초기에 0이였던 g_num의 값의 예상은 2로 기대한다.
그러나 예상과 다르게 g_num의 값은 1이되는 현상이 발생한다.
- 데이터레이스 해결
  - 공유자원을 안전하게 관리하기 위해선 '상호배제'기법이 필요하다. 공유자원을 모든 쓰레드/프로세스가 원하는 때 언제든지 접근 할 수 있도록 허용하지 않고, 쓰레드/프로세스의 접근을 제한적으로 허용하는 방식이다.
