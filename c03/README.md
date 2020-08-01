
## exercise 00, 01 : ft_strcmp, ft_strncmp

지난 시험에 나왔다가 시간 모자라서 결국 못 푼.. 

- 두 문자열이 같은지 비교하는 함수 (s1 - s2)
- 매뉴얼엔 이렇게 써있다. (나 왜 영어를 이해 못하누?)

The **strcmp**() and **strncmp**() functions lexicographically compare the null-terminated

strings s1 and s2.

- **사전적**으로 비교한다. null로 끝나는 스트링 둘을.. (lexiographically)
    - cat, bat이면 bat이 앞 → -1
    - cap, cat이면 cap이 앞 → +3
- strncmp의 경우, \0 뒤에 나오는 캐릭터는 비교되지 않는다고 한다. \0을 끝으로 인식하기 때문에. n이 100이든 1000이든 더 짧은 문자열 기준으로 비교한다.
- return 값은 정수로 나온다. (아스키 코드 기준)
    - 두 문자가 같으면 (s1 - s2) = 0 반환.
    - s1 < s2 = -1 반환
    - s1 > s2 = 1 반환
    - 윈도우 상에선 0, -1, 1을 반환하고 리눅스의 경우 positive, 0, negative값이라고 말하는데 그냥
    - 문자열 앞에서부터 차례대로 비교하다가 문자 값이 다를 때 그 차이를 반환한다. (아스키 값)
    - 결국 어느 게 더 사전적으로 앞에 오냐? 비교하는 함수임. 값은 크게 상관 없는듯.
- 첫번째 문자부터 차례대로 비교 ( hello 보다 < world가 더 큼)
- s1, s2 문자열의 크기가 다른 경우, 문자열 길이가 긴 것이 더 큼. (모든 문자 같다는 전제 하에) 왜냐면 \0이랑 비교하면 \0아닌게 더 크기 때문

## exercise 02 ,03: strcat, strncat

스트링을 읽는? concatenate 하는 것. → 파이썬할 때 배웠다. concat.. 더하는 거다!

man으로 부터.. → append a copy of null-terminated str2 to the end of null-terminated str1

s1 끝에 s2를 붙이는 것이다. 그리고 + '\0'를 붙여준다. 모든 문자열 끝엔 \0게 있어야 문자열이라 컴터가 인식하므로..

이 때 s1은 s2를 다 붙일 수 있는 sufficient space 가 있어야 한다. MUST HAVE!

ensure that no more characters are copied to the destination buffer than it can hold. 

- strncat의 경우, 딱 n개 문자만 s2에서 가져오며, 그 다음에 \0을 붙여준다.
- src와 dst의 문자열은 덮어씌워져서는 안된다.

반환값 > char *s1

## exercise 04 ft_strstr

haystack (str)에서 needle (str)을 찾아 반환하는 것이다. 

return 조건

- needle이 empty일 경우 빈 문자열 일 경우, haystack을 리턴한다.
- 못 찾았을 경우 NULL을 리턴한다. return (0);
- 찾으면 *needle 반환 pointer to first character
    - str + i (haystack에서 needle의 첫 위치 반환 ) = 그래야 그 뒤 src다 나옴
    - ex) str = 'hello worldly'
    - to_find = 'world'
    - return : worldly
- 아예 KO가 떠서 그냥 strncmp로 해야 될 것 같으요
- f

## exercise05 ft_strlcat

strcat(dest, src) → dest 뒤에 src을 뒤에 붙여줌 + src 뒤에 \0 붙임 

strncat(dest, src) → dest 뒤에 src 딱 n개만큼 붙여줌 + src 뒤에 \0 붙임 

strlcat(dest, src) → 만일.. unlimited space가 있었다면.. dest + src 해서 총 늘어난 length return.

`The strlcat() function returns the total length of the string that would have been created if there was unlimited space.`

실제 concat된 , actually created된 dest 크기와 다를 수 있다. 왜냐면 dest가 애초에 작았을 수 있으므로.

depending whether there was enough space. 

⇒ 원래 dst 크기 + src 크기 

⇒ len (dst) + min(size, len(src))
