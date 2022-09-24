# 소스 코드와 명령어
## 프로그래밍 언어의 종류
    1. High level
        - 인간이 좀 더 이해하기 쉽도록 만든 프로그래밍 언어
    2. Low level
        - 컴퓨터가 직접 이해할 수 있도록 만든 언어

### 프로그래밍 언어의 동작
- High level language로 작성된 언어는 반드시 Low level language로 변환되어야 실행이 가능함

### Low level language
- Low level language는 기계어와 어셈블리어로 나누어짐
    - 기계어 : 0과 1의 비트로 구성된 언어 (명령어 모음)
    - 어셈블리어 : 기계어를 인간이 이해 가능한 언어로 번역한 언어

### Compiler / Interpreter language
- Compiler language : 보통 소스 코드 전체를 low level language로 변환하여 실행하는 언어들을 지칭함
    - 소스 코드 전체를 훑어보는 과정을 거침 -> 만약 오류가 있다면 실패
    - 성공한다면 Object code (목적 코드) 라고 부름

- Interpreter language : 소스 코드가 한 줄씩 실행 및 변환
    - 전체를 훑지 않고 한 줄씩 실행하므로 오류 코드 줄에 들어가기 전까지 정상 동작

- Interpreter language는 보통 Compiler language보다 느림
    - Compiler의 목적 코드는 기계어로 이루어져 있으므로 한 줄씩 변환하는 Interpreter에 비해 빠를 수 밖에 없음

> 대부분의 프로그래밍 언어는 위의 두 가지 개념이 혼재되어 있기 때문에 완전하게 분리하는 것이 불가함