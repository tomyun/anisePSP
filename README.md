AnisePSP 프로젝트
=================

현재 이 프로젝트는 제가 PSP 를 다 팔아먹은 관계로 더이상 진행되지 못하고있습니다.  
20대 초반의 부유한 엔지니어 시절이 다시 찾아오면 그때 지름신께 제사 지내고 다시 시작하겠습니다.  
아쉽지만 현재는 PSP 에서 지속적인 개발 예정은 없습니다. (미정)  
(현재 지름신의 보호감찰하에 재활치료중임)

FAQ
---

이게 뭔가요?
-------------------------------------
미소녀 연애시뮬 에뮬레이터의 PSP 버전입니다. 그냥 게임 에뮬레이터입니다.

미연시 에뮬레이터가 뭔가요?
-------------------------------------
### 시뮬레이션과 에뮬레이션 용어의 차이점 ###
미연시 에뮬레이터에 시뮬이란 용어도 들어가고 에뮬이란 용어도 들어가니 좀 구체적으로 알고 싶은 사람을 위해서 설명하겠습니다. 먼저, 용어를 분석해보겠습니다.  
  
원래 시뮬이나 에뮬은 그 용어의 목적이 가상화에 있습니다. 용어 자체가 가상화를 표현한다는 것입니다. 그래서 시뮬레이션은 추상적 가상화를 의미하고 에뮬레이션은 구체적 작동가능한 가상화를 의미합니다.  
미소녀 연애시뮬은 연애를 하는 것을 시뮬레이션한 게임을 의미합니다. 연애를 추상적 가상화를 통해서 간접경험하게 해주는 게임을 의미합니다. 소설 처럼 말입니다.  
추상적인 가상을 경험하는 게임이라고해서 시뮬레이션 게임이라고 부릅니다.  
반면, 이런 시뮬레이션 게임을 작동시키는 기반은 컴퓨터라는 구체적인 기기입니다. 그런데, PSP 같은 게임기는 일반적인 컴퓨터가 아니라 다른 이기종 CPU 칩을 사용하는 기기입니다. 그러니 당연히 작동하려면 CPU 칩이 동일하지 않으면 작동이 될 수 없겠지요. 그래서 이 칩이 갖고있는 기계코드를 맞춰주는 작업이 필요한데 이런 작업을 흔히, 포팅이라고 부릅니다. 그리고, 이런식으로 변환되어 작동되는 것을 에뮬레션이라고 부릅니다.  
원래 미연시 게임은 x86 컴퓨터 도스용 게임이기 때문에 도스에서 작동하는 것처럼 PSP 에 가짜 시스템 환경을 꾸며주어야 하므로 가상화(가짜)이긴 하지만, 작동 자체가 칩에서 직접 작동하니까 소설이 작동하는 것은 아니기에 시뮬레이션이라는 용어는 사용할 수가 없습니다. 그래서 에뮬레이션(터)이라고 부르게됩니다.  
시뮬이나 에뮬이나 둘다 모사한다는 의미가 있는데 한쪽은 작동이안되고 다른 한쪽은 작동이 된다는 면에서 용어가 분류됩니다.

미연시 히스토리
-------------------------------------
개념적인 내용은 집어치우기로하고 이건 그냥 미연시 게임 에뮬레이터입니다. 단, PSP 에서 작동된다는 점만 다릅니다. 잠시 미소녀 연애시뮬레이션 게임이 뭔지 궁금해하시는 분들을 위하여 적어보겠습니다. 제가 변태가 아님을 증명하기 위한 노력은 아닙니다. 미연시 게임을 한번이라도 해본 사람은 누구나 다 느낄 수 있는 것을 적는 것입니다. 90년대 초반 미소녀 연애시뮬(약어: [미연시](http://mirror.enha.kr/wiki/미소녀 연애 시뮬레이션 게임))이라는 일본판 H게임(변태게임)이 국내에 본격적으로 상륙을 하게되었었습니다. 그리고 곧 광풍을 불러일으켰습니다. 불행중 다행(?)인 것은 그 당시 국내에 인터넷 문화가 지금처럼 되어있지 않았고 저처럼 일부만 인터넷을 사용하고 있었던 시절이었습니다. 그러다보니 사회적인 현상으로 대두되어도 전혀 문제가 없을 법할 정도로 미연시 열풍이 불었으나 전혀 화두가되지 않았습니다. 물론, 남자들의 세계에서는 엄청난 화두였으나 오직 남자들의 세계 밖으로는 이 소문이 새어나가지 않았습니다. 그 덕택에 그 어떠한 외압(여성부 처럼)도 없이 안전하게 미연시 문화가 꽃을 피울수 있었습니다. 무엇보다 미연시라는 것이 주는 의미는 비주얼노벨이라는 게임장르가 국내에서도 인식되었다는 점에 있습니다. 또한, 일본의 동인지(소설 내용과 그림이 함께있는 소설책)라는 것이 주목받았습니다. 수많은 음란물과 저급물이 범람하였지만 그 속에서도 진주알 같은 깨달음이 있었고 그것을 발견하는 사람들이 있었습니다. 소설책과 같은 깊은 감동이 그림과 어울어지는 특이한 경험은 동인지와 비주얼노벨이라는 게임장르를 통해서 소개되었습니다. 만약 지금의 인터넷 문화처럼 조금만 오용되거나 남용되더라도 냄비근성으로 들썩이게되면 금새 외압의 손길이 미치게 되어 불법 딱지를 붙였을 것입니다. 한두개가 나쁘다고해서 전체가 다 나쁜 것처럼 싸잡아서 법제정을 해버리는 어리석은 정부나 단체의 행동이 있었을 것이 눈에 선합니다. 그러나, 당시에는 인프라가 갖추어져 있지 않은 디스켓으로 공유하던 시절이라서 그러한 제재는 빗겨나갈 수 있었습니다.  
당시 게임 중에서 많은 사람들이 기억하고있는 게임이 바로 동급생일 것입니다. 동급생1과 2가 있지만 동급생1이 명작이었는데 말 그대로 미연시가 뭔지 제대로 보여준 명작이었습니다. 처음에는 누구나 다 음란물로 생각하고 호기심에 게임을 시작했다가 게임을 다 끝내고나면 뭔가 가슴이 뻥뚫린 느낌을 받게됩니다. 누구나 소설책을 다 읽고난 후에 허전함을 메우지 못해서 다른 비슷한 장르의 소설책을 찾아다닌 경험이 있을 것입니다. 이렇듯 게임을 다 플레이한 후에 허전한 듯한 깊은 여운을 남게해주는데 이런 게임이 바로 명작 미연시 게임의 진짜효과입니다. 명작소설과 거의 동일한 효과입니다.
그래서, 성인이 된 후에도 이런 미연시 게임 에뮬레이터를 만드는 것은 아닐까요? 아직도 그때의 여운이 남아있기 때문에?  
게임은 재밌게 했지만 이 게임을 돌리기 위해서 들어가는 기술은 결코 장난이 아니랍니다.  
에뮬레이터 원본 코드를 제작한 분들 정말 대단한 사람들인 것 같습니다. 저는 기기에 맞게 포팅한 수준 밖에 안됩니다.  

원작과 포팅에 대한 이야기
-------------------------------------
본 에뮬레이터의 원래 프로그램 소스는 제가 제작한 것이 아닙니다. 저는 PSP 용으로 해당 소스가 작동가능하게 포팅만 하였습니다. 포팅은 핵심 코드는 그대로 두고 팔다리에 속하는 부분들을 잘라내고 붙이고 하여 호환되도록 구조적으로 변경시키는 작업을 의미합니다. 코어에 해당하는 원본 코드는 포팅하는 프로그래머들이 쉽게 접근할 수가 없습니다.
에뮬레이터의 원작자 코드는 아주 잘 만든 코드에 속한다고 생각합니다. 최대한 구조적으로 아름답게 짜려고 노력한 흔적이 보이며, 진짜 많은 노력이 들어간 것을 코드의 양으로 알 수 있습니다. 본 프로그램이 일반적인 프로그램이었다면 모르겠지만 리버스 엔지니어링(역공학) 기술에 바탕을 두고 있음에 더욱 놀랍습니다. 역공학 기술은 프로그래머들 중에서도 극히 고수들만이 사용하는 기술입니다. (학교/학원 따위에서는 절대로 알려주지 않는 기술)
원래 전 개발자가 아니고 프로그래머입니다. 얼마전까지 보안컨설턴트(보안업종의 모의해킹을 해주는 전문해커)였습니다.
8년 전 PSP 에서 취약점 찾는 연구를 하다가 재밌을 것 같아서 포팅까지 하게되었습니다.  

더 알고 싶어요!
-------------------------------------
제 개인 홈페이지이기도 하고 1인 창업 홈페이지이기도 한 [amesian.net](http://amesian.net) 가 있습니다.  
아직은 내용도 없고 프로젝트 홈만 만들어놨는데 공사중입니다.  
점차 anise 처럼 재밌는 프로젝트들을 더 많이 할려고 그럽니다. 근데, 돈을 벌어야 재밌는 프로젝트들도 계속 유지할 수  
있겠더라구요. 언제까지나 중2로 살고 싶은데 세상이 가만 놔두지 않네요..  T.T
원작자의 [홈페이지](http://tomyun.pe.kr/projectanise/)가 아직 살아 있습니다.  
원작자의 github 는 https://github.com/tomyun/anise 여기입니다.  
원작자의 github 에 브랜치로 두고 싶지만 브랜치하는 방법을 몰라서 따로 만들었습니다.


제작자 노트
-------------------------------------
파워해커 운영자 AmesianX 입니다. 반갑습니다.  
게임을 실행해보려고 하신 용기가 참으로 가상하다고 생각하여..  
몇가지 조언을 드릴려고 합니다. -_-;  
아참.. 그리고 이건 제가 PSP 용으로 포팅을 했지만 PSP 에 알맞게  
돌아갈 수 있도록 팔다리 잘린거 다 이어붙이고 뭐 그런역할을 한 것이지  
실제 핵심엔진은 원 제작자가 알고있는 것만큼 알지 못합니다.  
(그래서 버그잡이가 힘듬) 왜 이렇게 만들었냐는 식의 원망은 일단 피하고자.. -_-;  

설명서
-------------------------------------
O 버튼    : 확인  
X 버튼    : 취소  
네모 버튼 : SHIFT (기능은 있으나 게임에서 필요없음)  
세모 버튼 : END   (기능은 있으나 게임에서 필요없음)  
LTRIGGER  : 마우스 속도 감소  
RTRIGGER  : 마우스 속도 증가  
START     : 글씨 빨리넘기기(CTRL 역할)  
SELECT    : 게임종료  

### 주의 ###
게임종료 시 HOME 버튼을 누르고 바로 게임을 종료시키면 종료가 안될겁니다.  
SELECT 버튼을 한번 눌러주시고 HOME 버튼을 눌러서 종료시키셔야 내부작동이  
멈추기 때문에 정상적으로 종료됩니다.  

### 설치 ###
PSP 를 연결하시면 J: 드라이브라고 가정했을때를 기준으로 설명합니다.  

### 실행될 EBOOT.PBP 파일이 위치하는 경로 ###
[1.50 사용자]  
J:\PSP\GAME\anisePSP  
J:\PSP\GAME\anisePSP%  

[1.00 사용자 및 커펌 DarkAleX OE-B 사용자]  
J:\PSP\GAME150\anisePSP  

위와 같이 실행될 EBOOT.PBP 파일이 위치할 경로를 해주셨으면  
이제 설정파일과 게임이 들어가야할 경로입니다.  

### 게임과 설정파일이 위치해야할 경로 ###
J:\anisePSP 라는 디렉토리를 만들어주십시오.(디렉토리 이름은 똑같아야함)  
그 안에 게임을 집어넣습니다. 그리고 압축파일에 들어있는 anisePSP.cfg 라는  
파일을 이곳에 넣어주십시오.  
게임을 집어넣은 디렉토리 이름은 마음대로 지정해주셔도 됩니다. 어차피  
anisePSP.cfg 에 적어주셔야 하기 때문이지요..  

### J:\anisePSP\anisePSP.cfg 파일 수정법 ###

[ANISEPSP]  
GAMEPATH="ms0:/anisePSP/nanpa1"  
GAMENAME="nanpa1"  
SOUND="0"  
LANGUAGE="korean"  

(주의사항) 위의 환경설정 파일에서 보는것처럼 값들은 꼭 " " 로 둘러싸야합니다.  
GAMEPATH 에는 게임을 복사한 경로를 지정해주셔야 합니다.  
SOUND 는 (0: Off, 1: 11025hz, 2: 22050hz, 4:44100hz) 를 의미합니다.(3은 없음)  
SOUND 에는 0을 주십시오.. 안그러면 속도가 엄청 느려질겁니다.  
LANGUAGE 에는 korean 을 지정해주시면 한글입니다.(한글패치된 게임일 경우만 해당)  
다른 것이 지정되면 무조건 일본어입니다.  
  
그리고 GAMENAME 은 지정되어 있는게 몇가지 있습니다.  
  
nanpa1   : 동급생1 (침대에서 "잔다" 를 클릭하면 게임정지됨: 버그있음)  
nanpa2   : 동급생2 (세이브도 잘되고 게임잘됨)  
aisimai  : 무슨게임? (테스트 안해봄)  
crescent : 크레센트 (테스트 안해봄)  
isle     : 실낙원 (테스트 안해봄)  
kawa     : 하원기가의 일족 (게임잘됨)  
nono     : 노노무라 병원 (테스트 안해봄)  
  
지정된 게임이름을 지정하지 않으면 최적화된 옵션을 사용하지않고 게임이 실행됩니다.  
운 좋으면 될수도 있고 안될수도 있단 소립니다.. -_-;  
