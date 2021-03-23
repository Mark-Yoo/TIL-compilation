# 토이 프로젝트 진행 중 마주한 에러에 대한 해결책 - 백엔드 편

---

1. ERROR: connect ECONNREFUSED 127.0.0.1:3306

   - 에러가 발생하는 이유로는 다양한 이유가 있어보이지만 mysql 8버전의 비밀번호 authentication 방식의 변화로 이러한 에러가 가끔 발생하기도 하는 것으로 보인다.  나의 경우 mysql을 다시 재시작하는 것으로 문제가 사라지긴 하였으나 다양한 에러 상황을 생각해놓는 것이 좋아보인다.

   - 해결방법

     ```zsh
     // 서버 시작
     mysql.server start
     // 재시작하기
     mysql.server restart
     ```