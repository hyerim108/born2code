# Description
> Eat, Sleep, Spaghetti, repeat. This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger.

### Data race
> 여러 스레드/ 프로세스가 공유자원에 동시에 접근하려 할때, 일어나는 경쟁상황
+ 한스레드와 또다른 스레드가 동시에 한 변수를 쓰려고 할 때, 한 스레드는 한 변수를 쓰고 있는데 다른스레드는 그 변수를 읽으려고 할때 당의 상황에서 발생한다.
아래는 간단한 예시
``` g_num = 0;

void    add(void)
{
  g_num++;
}
