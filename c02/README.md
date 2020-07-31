>c02를 하며 정리한 것들..

c02 리트 전 코드 고쳐야 할 것

- [ ]  strlcpy size 0일때 값과 비교해서 고치기
- [ ]  캐피털라이즈 원형 제거
- [ ]  11번 unsigned char로 바꿔주기 (char가 음수일 경우 확장된 아스키까지 커버 x)

## exercise 00 : ft_strcpy

함수 strcpy (스트링 커피)를 재현하는 것.

`char  *ft_strcpy()` 라고 되어있으면 반환하는 것은 무조건 포인터란 뜻이다.

즉 캐릭터를 가리키는 포인터를 반환하라..는 뜻. 이 경우 바뀐 char *dest를 반환하는 것.

**문자열을 받는 배열/포인터의 경우 중요한 점**

- index가 5이면 size는 6이다.(+1) 모든 char형 배열은 무조건 '\0' null 문자가 마지막에 저장된다. 컴퓨터는 문자열의 끝을 \0 으로 이해한다.
- strcpy는 무조건 \0까지 복사한다. \0을 복사하면 할 거 다했다~고 생각함.

testcase 를 여러 개 만들어서 테스트 해야함. (원 함수와 정확히 똑같게 기능해야 하기 때문에)

1) dest가 src보다 크거나 같을 경우 → OK. dest에 src보다 더 길게 뭔가 있었다면, 없어진다. src들어올 때 \0까지 복사했기 때문에, 그게 문장의 끝이 된다.  

2) dest가 src보다 작을 경우 →  터미널에서 `abort` 가 뜬다.

이렇게 썼다. 

```c
char *ft_strcpy(char *dst, char *src)
{
	while (src[i++]) //while문 값이 0이 되면 멈추기 때문에.
										//str 배열 끝엔 무조건 \0가 들어있다. 
	{
		dst[i] = src[i];
	}
}
```

- sizeof 얘기
- char a[], char *a

## exercise01 : ft_strncpy

[https://blockdmask.tistory.com/348](https://blockdmask.tistory.com/348)

스트링 커피와 다른 점은 딱 n개 만큼만 복사한 단 것이다.

얘는 절대 \0은 복사하지 않는다. (sizeof(src) 가 n 값이면 몰라두)

- strncpy 기능에 대해서 살짝 정리해놓았다.

src, dst, n까지 테스트 케이스를 정리하자. 

- 테스트 케이스

겁나 줄줄 정리도 했는데,, n은 애초에 인풋 값이므로 dst +1 값만큼 넣지는 않는다고 생각했나보다. 

결국 ft_strcpy와 비슷한데, 고민해야 할 지점은

1. `/0`을 복사해 주지 않기 때문에, 필요한 지점에 `/0`을 복사해 넣어야 한다는 것
2. 그 외는 없는 거 같다.. 

## exercise10 : ft_strlcpy

00번, 1번이랑 이어져서 요기에 정리.

문자열을 복사하는 함수들이다. 

1. strcpy (dest, src) ⇒ 무조건 src 전체를 **( \0 포함 )** 복사한다. dest 원래 값은 없어진다.
2. strncpy (dest, src, n) ⇒ 딱 n 만큼만 복사한다. (\0 포함 x) n은 dest 사이즈보다 (\0까지 +1) 작거나 같을 수 있다. src보다 n이 클 경우, \0까지 데려와 복사한다. dest보다 n이 작은 경우 dest 원래 값이 뒤에 남는다. 
3. strlcpy (dest, src, n) ⇒ n만큼 복사하되, n에 \0을 포함한다. 3을 복사하면 src에선 2개만 데려오고 나머지 1은 \0이다. n-1만큼 복사하고 dest[n-1] = \0이다. (인덱스는 0에서 시작이니까)
    1. n이 src보다 훨씬 크면 맨 끝에 무조건 \0을 넣어준다. (오류 방지) dest는 src 크기보다 +1 됨.
    2. 안녕하세요 김용준입니다. 저는 15인치 맥북을 사용중입니다. :) 

- [x]  capitalize 하는 함수 체크하기 (+, - 부분) - main함수 제외, 프린트 제외
- [x]  ex01 strncpy 다시 쓰기
- [x]  04 alpha.c or 연산자 | 인지 || 두개 써야 하는지
- [x]  printable && 연산으로 바꿀것
- [ ]  


### exercise 11 : ft_putstr_non_printable

non printable characters ⇒ 소문자 hexadecimals (16진수)로 바꿔주기

1. 10진법을 16진법으로 바꾸는 방법
    1. 몫이 0이 될 때 까지 나머지를 계속 16으로 나눠줌
    2. 아스키 코드로 변환할 경우
        1. if (r < 10) → ch + 48 ('0' 더하면 그대로 숫자 문자 나옴)
        2. if (r > 10) → ch + 87 (더하면 'a')

exercise 12 문제도 안 읽어봄
