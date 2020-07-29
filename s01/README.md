# projects C Piscine Shell 01
오늘 한 거 정리해볼까?

tar 파일 압축 해제 명령어

```bash
tar -xf testShell00.tar
# x는 해제
# f는 파일 이름 지정
```

## exercise 1 : print__groups

환경변수 FT_USER에 포함된 login이 소속되어 있는 그룹의 목록을 표시하는 명령어를 작성하세요. `id`
공백 없이 쉼표로 분리되어야 합니다. `sed` & `tr -d`

[http://blog.naver.com/PostView.nhn?blogId=koromoon&logNo=220793570727](http://blog.naver.com/PostView.nhn?blogId=koromoon&logNo=220793570727)

- 환경변수란? `env`
    - 쉘에서 정의되고 실행하는 동안 프로그램에 필요한 변수를 나타냄
    - (어려운 말로.. "프로세스가 컴퓨터에서 동작하는 방식에 영향을 미치는 동적인 값들의 모임")
    - user=dachung, home=/Users/dachung, colorterm=truecolor, shell=/bin/zsh 등..
    - 동작 범위에 따라 크게 환경 변수를 1. 로컬 환경 변수 (현재 세션에서만 동작) 2. 사용자 환경 변수 (특정 사용자에 대해서만) (.bashrc 등) (← 이거 touch -t 할때 타임스탬프 설정할 때 수정했던 거) 3. 시스템 전체 환경 변수 라는 게 있음.

```bash
#환경변수 설정
export FT_USER=dachung
#환경 변수 설정 후 해당 터미널 세션 내의 스크립트 에서 $를 붙여 변수 이름으로 쓸 수 있다

#id 사용
id -Gn $FT_USER
```

- `id` 는 유저/그룹 id 및 정보를 출력하는 명령어, `id option username`
    - `-g` print effective group id  (이 경우 하나 밖에 안나옴 맨 앞의 거)
    - `-G` print all group id
    - `-n` 이름 출력, 안 쓸 경우 숫자 id 출력됨

```bash
#공백 없이 쉼표로 분리 되어야 함 + 마지막 값 출력되며 디폴트로 나오는 엔터 삭제
id -Gn $FT_USER | sed 's/ /,/g' | tr -d '\n'
```

- `sed` 는 stream editor로 원본 변화 없이 출력 결과를 변화함
- `'s/[바꿀거]/[바뀔거]'` << 따옴표로 묶어줌, s는 치환한다는 뜻 substitute
- `g` 는 global로 없으면 첫 필드? ($1?) 첫 문자열 공백에서만 가동함. 뒤의 문자열까지 해줘야 하므로 붙이기
- `tr -d '없앨거'`  는 아마 delete로.. 출력 마지막에 없애줌. >>

## exercise 2 : find__sh

현재 디렉토리와 그 하위 디렉토리들에서 파일 이름이 ’.sh’로 끝나는 (따옴표제외) 모든 파일을 찾는 명령어를 작성하세요. `find`
sh를 제외한 파일 이름만을 표시해야 합니다. `sed`

문제

```bash
#우선 현재 디렉토리 & 그 하위 디렉토리에서, 파일 이름이 , '.sh' 로 끝나는 것 찾긔
find . -type f -name "*.sh"

#파일명 뽑아주긔
find . -type f -name "*.sh" -exec basename {} \;

#.sh 지워주긔
find . -type f -name "*.sh" -exec basename {} \; | sed 's/...$//'

#사실 sed를 안써줘도 된다..! (어쩐지) basename 자체가 파일명 뽑아주는 명령어다. 확장자 없애주는 기능이 없을리 없다.
basename {} .sh \;
##이걸 해주면 .sh 확장자가 날라간다 한다. 역시.. 구글링은 힘이다. 
```

- 위 명령을 실행하면, 파일 경로가 붙어서 나온다. `./file1.sh, ./find_sh.sh` 등
- 파일경로에서 파일 명만 뽑아 쓰는 `basename` 을 쓰자
- `-exec` 은 뒤에 붙을 명령어가 한 줄 한 줄 처리 될 것이라는 뜻
- {} 는 실행 명령어( `basename` ) 에 필요한 argument
- \; 는 해당 줄을 끝내기 위한 거라고 하네용
- cf) 참고! rm *로 파일이 지워지지 않을 때 쓸 수 있는 것
    - `find . -type f -exec rm -rf {} \;`
- `s/...$//` 이거는 끝에서 세번째까지 다 지워주자는 뜻
- cf) `dirname` 얘는 경로만 추출

## exercise 3 : count__files

현재 디렉토리 및 그 하위의 모든 디렉토리에 있는 일반 파일 및 디렉토리의 개수를 `find`
세어 표시하는 명령어를 작성하세요. `wc` 
여기에는 시작 디렉토리인 ’.’도 포함되어야 합니다. (상위는 제외)

```bash
# 모든 일반 파일 및 디렉토리
find . -type f -o -type d

#개수 세주는 함수 word count
#옵션은 -l line을 세주는 걸로 해서 결과 값의 라인을 세는 것이 곧 개수이기 때문에 ㄱㅊ 
| wc -l

#앞에 공백이 붙어서 나오므로 공백도 삭제해주기
| tr -d " "
```

cf) `ls -alR` ls -al만 하면 하위 디렉토리에 있는 파일까지 나오지 않는다. alR을 해줘야 하위 디렉토리 파일까지 다 나옴

cf) 처음에는 ls -alR을 하면서 그 중 디렉토리 일반파일만 가져오기 위해 `grep ^[d-]` 사용했음. 줄 시작이 d거나 -인 애들 추출한다는 뜻

- wc 명령어 참고 [https://nota.tistory.com/55](https://nota.tistory.com/55)

## exercise 4 : MAC

컴퓨터의 MAC 주소를 표시하는 명령어를 작성하세요. `ifconfig`
각 주소 다음에는 줄바꿈이 나타나야 합니다.

- ifconfig 라는 명령어는 네트워크 인터페이스 (if) 의 파라미터를 설정한다 (configure) 는 뜻이라는데..
- 서버 관련 용어는 당최 이해가 안간당..
- 여튼 ifconfig 하면 어쩌고 저쩌고 하는데 여기서 `ether` 이 부분이 주소다
- 그러면 ether 들어가는 부분만 가져오면 된다 `grep 'ether '` (`^ether`로 하면 안나오는게 앞에 공백이 있어서 안 나오는 듯) (뒤에 공백은 꼭 붙여준다 안 붙여주면 이상한거도 같이 나온다)
- 여기서 앞에 공백과 ether를 지워준다 딱 주소만 나와야 하니까

```bash
ifconfig | grep 'ether ' | sed 's/.ether.//'
```

- 줄바꿈까지 잘 나타나는지 확인하고 고고

## exercise 5 : Can you create it?

오직 "42" 만 포함하고 그 밖의 어떠한 것도 포함하지 않는 파일을 작성하세요. `ctrl d 연타`
파일 이름은 다음과 같아야 합니다: "\?$*'MaRViN'*$?\" `역슬래쉬로 해결`

- 특문을 문자열로 쓰려면 모든 특문에 \ 를 넣어 감싸주고.. (마빈 제외)
- 에디터로 42 치면 2 byte를 넘어가니, 에디터가 아니고 cat으로 만들어야 한다.

```bash
cat > file 로 만들고 42 누르고 ctrl d 를 2번 연타하면 된다.
#첫번째는 파일 종료
#두번째는 cat process를 종료하는 방법이다. 
```

그리고 완성하면 마빈 파일 이름에 엔터가 붙어있다. `tr -d '\n'` 로 제거해주자. 

그리고 원래 touch -t 로 파일 생성 시간 바꿔주면 타임스탬프 부분에 연도가 찍혔는데.. 연도를 2019로 하니까 이번엔 그냥 시간이 찍혔다 (!)

원리는 모르겠다. 여튼 성공. 

## exercise 6 : Skip

ls -l 명령어의 첫번째 행부터 시작하여 한 줄 걸러 보여주는 명령어를 작성하세요. 

요거는 방법을 2가지 발견했다. 

[https://recipes4dev.tistory.com/171#314-%ED%8A%B9%EC%A0%95-%EB%A0%88%EC%BD%94%EB%93%9C%EB%A7%8C-%EC%B6%9C%EB%A0%A5%ED%95%98%EA%B8%B0](https://recipes4dev.tistory.com/171#314-%ED%8A%B9%EC%A0%95-%EB%A0%88%EC%BD%94%EB%93%9C%EB%A7%8C-%EC%B6%9C%EB%A0%A5%ED%95%98%EA%B8%B0)

1. `awk` 프로그램
    - 파일로부터 record (줄) 선택하는 명령어
    - 선택된 레코드에 포함된 값 조작 하거나 데이터화 할 수 있다.
    - awk ' 패턴 { 액션 }' 파일 > 이렇게 사용함
    - 특정 레코드만 추출하는 방법
        - awk ' NR == 2 { print } ' → 두번째 레코드만 프린트 해라
        - awk ' NR  > 2 { print $0; exit } ' → 두번째 레코드 이상 (3부터) 프린트 하는데, $0 하나만 하고, exit 해라!
            - print $0 레코드 하나 하고 **세미콜론 ; 빼먹지 않기**!! 일단 프린트로 처리 끝내준 다음 처리임
            - 값은 세번째 레코드 하나 나옴
        - awk ' { print $5 }' → 다섯번 째 필드 변수를 뽑아라. (공백으로 구분됨) (다섯번째 레코드 아니고 공백이 있으니 필드!)

    ```bash
    # NR = number of records 변수 지정 
    ls -l | awk ' NR % 2 == 1 { print }' 

    #이러면 홀수 행만 나온다. 
    ```

    [https://zzsza.github.io/development/2017/12/20/linux-6/](https://zzsza.github.io/development/2017/12/20/linux-6/)   위보다 이게 더 설명 잘해 논거 같기도. 

    [https://heoly.tistory.com/entry/원하는-열만-추출하는-기능awk](https://heoly.tistory.com/entry/%EC%9B%90%ED%95%98%EB%8A%94-%EC%97%B4%EB%A7%8C-%EC%B6%94%EC%B6%9C%ED%95%98%EB%8A%94-%EA%B8%B0%EB%8A%A5awk) 그냥 참고 

2. `sed` 프로그램

## cf) 리눅스 정규 표현식과 패턴 검색

[https://zzsza.github.io/development/2017/12/13/linux-3/](https://zzsza.github.io/development/2017/12/13/linux-3/)

sed, grep 쓸 때 필요하다. 

[http://www.incodom.kr/Linux/기본명령어/sed#h_03b99947ab0db6a54a7b644acb91ac87](http://www.incodom.kr/Linux/%EA%B8%B0%EB%B3%B8%EB%AA%85%EB%A0%B9%EC%96%B4/sed#h_03b99947ab0db6a54a7b644acb91ac87)

sed 연산자 

- [범위]/p: 지정 범위 출력 (print)
    - sed -n '3,7p' 파일 → 파일에서 3~7라인만 출력
- [범위]/d: 지정 범위 삭제 (delete)
    - sed '3,7d' 파일 → 파일에서 3~7라인 제외하고 출력
    - sed '**n;**d' 파일 → 파일에서 한 줄 건 너 한 줄씩 제외하고 출력 → n이 첫 행이 아닌 다음 행부터 처리 라는 뜻이래 →  질문
- [범위]/문자1/문자2: 지정된 범위의 처음 나타난 문자를 문자2로
- s/문자1/문자2/: 문자1을 2로
- g: 모든 라인에 적용

## cf) ls 명령어 옵션

ls -lr 파일명 기준으로 내림차순 정렬. 

[https://story79.tistory.com/entry/ls-명령어-옵션들](https://story79.tistory.com/entry/ls-%EB%AA%85%EB%A0%B9%EC%96%B4-%EC%98%B5%EC%85%98%EB%93%A4)

## exercise 7 : r__dwssap

cat /etc/passwd 명령어의 출력 결과에서 
주석은 삭제하고 
두 번째 행부터 시작하여 다른 모든 행들은 출력하되,
각 login들 거꾸로 반전시키고 알파벳 역순으로 정렬한 후, 
FT_LINE1 과 FT_LINE2 을 포함한 그 사이의 값들만 남겨두세요. 
이 때, 각 login은 ","로 구분되어야 하며 출력 결과는 "."로 끝나야 합니다.(큰따옴표 없이)

천천히 한 줄씩 명령어를 써나가면 된다.

1. 맨 위 주석은 #로 시작하는 거라서 대부분 `sed '/^#/d'` 이렇게 삭제 한듯. 나는 앞 10줄이 주석이니까 

    ```bash
    #주석 삭제하기 (앞 열줄, :이하 쭉 삭제 해준다는 뜻의 regex ㄱㄱ)
    awk 'NR > 10 { print } ' | sed 's/:.*//' |

    #주석 삭제 이게 제일 많이 쓰더라. -v는 패턴에 포함되지 **않는** 애들만 골라주는 것. "#"로 시작하는 애들 제외.
    grep -v '#'

    #cut 사용하는 사람도 있다. (d 뒤에 붙는 캐릭터 다음으로 다 잘라라) (필드는 공백 없어서 첫번째거)
    cut -d : -f 1
    ```

2. 두번째 행부터 시작하여 한 줄 걸러 한 줄 출력 + 거꾸로 반전 + 역순 정렬

```bash
#이건 쉽다.

awk 'NR % 2 == 0 { print }' | rev | sort -r
```

3. 환경변수 들 사이 값들만 남겨두기 = 사이 값만 출력하기

```bash
#환경변수가 환경에 따라 달라지는 변수다.. 일케 생각하는 중.. 
#이 부분이 제일 어려웠다. 변수 {} 이런거랑 겹쳐서. 

sed -n "${FT_LINE1}, ${FT_LINE2}p"

#sed에서 보통 ~어디서 ~어디 사이만 출력하라는 이렇게 쓴다. 
sed -n '3,7p' 
```

근데 환경변수 쓸 때는 쌍따옴표로 묶어줘야 한다. 그리고 원래 변수 앞에 $FT_LINE 하고 붙는데 `sed` 에서 범위 지정 해줄 때 변수를 쓰면 저렇게 `{}`로 묶나보다.  

[https://stackoverflow.com/questions/45308549/using-variables-in-command-line](https://stackoverflow.com/questions/45308549/using-variables-in-command-line)

이유를 찾았다!

변수를 { } 로 묶어주는 이유는 쉘이 변수 이름이 어디서 끝나는지 알기 위해서라고 한다. 그니까 변수 써주면 맨날 써줘야 됨.. 

' '가 아닌 " " 로 묶어주는 이유는 ' '로 둘러쌓인 변수는 쉘에서 확장이 안되며, 따라서 sed가 인자를 '$FT_LINE1, FT_LINE2p' 이렇게 문자 그대로 받는다고 한다. literally. 여튼 변수는 " "로 묶어주자. " "는 구문을 해석해주지만, ' '는 그런 능력이 없다. #interpolate 

출력할 때 반드시 옵션 `-n` 생각할 것. 반대로 3~7줄 삭제하라 할 때는 이렇게 쓴다. `sed '3,7d'` 얘는 -n 안 쓴다. 

사실 이거는 모르니까 검색하면 나오는 거고.. 아래가 제일 어려웠다. 정규 표현식에 안 익숙해서..

4. 각 login은  , 로 구분되어야 하며 출력 결과는 . 로 끝나야 한다

```bash
#값을 보면서 해야 좋은데.. 지금 한줄로 엔터 쳐져서 늘어진 상태. 레코드 마지막을 , 로 치환하고, tr로 개행을 다 잡아준다. 
sed 's/$/, /g' | tr -d '\n' 
#마지막 toor_, 값에서 뒤에 ,빈칸 을 .. 로 잡아서 .로 바꿔준다. 
sed 's/..$/./'
```

## exercise 8 add_chelou

’\"?! 를 밑으로 하는 숫자를 FT_NBR1 에서 가져오고 
mrdoc 를 밑으로 하는 숫자를 FT_NBR2 에서 가져온 후,
두 수의 합을 구해
gtaio luSnemf 이 밑인 숫자로 나타내시오.

이 말도 안되는 문제는 뭘까..?

~를 밑으로 하는 숫자

= ~를 베이스로 하는 숫자

= ~를 진법의 기초 문자로 하는 진법. 

그니까 ~만 사용해서 숫자를 쓰겠다 이 말이다. 

저 특수 5문자 사용하는 진법과 영 5문자 사용하는 진법이 연산 되려면, 01234를 사용하는 5진법으로 바꿔줘야 한다. 이 때 우리는 `sed` 치환 프로그램이 있다!

```bash
#echo는 파이프 라인 뒤의 커맨드 값을 보고 싶을 때 쓴다. 물론 원래는 기본 출력창에 주어진 값을 뱉음. 퉤
# ' 를 0으로 바꿔주는 과정에서, sed 문법의 '와 겹치므로 이 경우 "를 써서 묶어줌.
echo $ft_nbr1 + $ft_nbr2 | sed -e "s/\'/0/g" -e 's/\\/1/g' 

#이렇게 뒤를 해주고.. 특수문자는 이스케이프 문자를 써야 되서 하나하나 바꿔줬지만, 문자는 빠르게 tr(anslate) 명령으로 치환하자.
| tr "mrdoc" 01234

#그 다음엔 계산을 해줘야지. + 만으로는 계산이 안된다. bc 라는 리눅스 계산기를 써줘야 한다. 근데 이 bc는 이렇게 쓴다.
echo 3 + 5 | bc
##앞의 에코가 뒤의 bc 명령을 받아서 값을 출력해준다. 그러면 우리는 또 echo를 써야지. 대신 앞의 x + y를 받아주자. 
#그리고 bc는 입력 베이스, 출력 베이스, 소숫점 자리까지 정해줄 수 있다. 
echo 'ibase=10;obase=5;scale=2;8/3' | bc
##10진법으로 입력되면 출력값은 5진법으로 하고, 소숫점 2+1=3자리까지 보겠단 뜻이다.
| xargs echo 'ibase=5;obase=23' | bc
##근데 왜 13진법 (저 gtaio어쩌구 다 더하면 13임) 이 아닌 23진법이냐.
```

`ibase`가 5진법으로 들어가면 결국 `obase`를 읽는 것도 5진법 기준인 것 같다. 10진법 13은 5진법 23이다. 따라서 obase=23으로 해야 13진법으로 먹힘. 

⇒ obase를 먼저 쓰면 obase 진법 기준으로 ibase를 작성해야 한다! obase=13;ibase=5; 로 쓸 수 있다. 

그럼 이제 `tr`로 막타를 치자.

```bash
| tr "0123456789ABC" "gtaio luSnemf"
```

끝. `bc`는 복잡한 연산이 가능하고 `echo` 와 `pipe`를 이용한다. 

tr 명령에 대한 옵션 설명. 

tr 옵션 문자열1 문자열2

tr -d '어쩌고' → 어쩌고 삭제 후 출력 delete

tr -s "문자열 " → 반복되는 문자 삭제 substitute

tr -t "문자열1" "문자열2" → 문자열1을 2 길이만큼 자름 trim

awk 추가 옵션

awk -F ' : '  → : 앞뒤로 잘라주세요. 저러면 공백이 생겨서 필드 #1만 프린트 하면 된다. awk -F ':' | awk ' { print $1} '
