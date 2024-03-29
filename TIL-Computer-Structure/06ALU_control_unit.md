# ALU and Control Unit
## ALU
- ALU 기본적으로 제어장치를 통해서 어떤 연산을 수행할지 제어 신호를 받고 레지스터를 통해서 피연산자를 받아 작업을 수행함
- ALU는 결과와 같이 플래그를 내보냄
    > 간혹 연산의 결과가 결과가 담길 레지스터보다 클 경우를 오버플로우 라고 한다.

### 플래그의 종류
- 부호 플래그
- 제로 플래그
- 인터럽트 플래그
- 슈퍼바이저 플래그
- 오버플로우 플래그
- 캐리 플래그

각 플래그는 0과 1 값으로 참인지 거짓인지 구분함

## 제어장치
- 부품들의 관리하고 작동시키기 위한 전기 신호
    1. 제어장치는 클럭의 신호를 받아들임
    > 클럭이란 컴퓨터 부품을 움직이는 시간 단위 : 클럭 한 주기에 맞추어 모든 것이 동작한다기 보다는 각각의 명령어가 각자의 주기를 가지고 클럭에 맞추어 동작한다는 것이 더 알맞음

    2. 제어장치는 해석해야 할 명령어를 받음
    - 해석을 요하는 명령어는 ***명령어 레지스터***에 저장됨

    3. 제어장치는 제어 버스로 전달되는 제어 신호를 받음
    - 제어 장치는 CPU 외부와 내부로 전달하는 제어 신호가 있음