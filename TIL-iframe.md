# iframe에 부연 설명

iframe 사용을 처음 하는 사람들의 이야기를 듣다보면 가장 자주 받게 되는 질문이 '이 페이지에서 연결을 거부했다고 나와요' 이다. iframe을 일반적으로 사용 가능하게 하면 문제가 생길 수 있다는 게 많은 사람들의 설명인데 (이는 네트워크에 관한 어느정도의 지식을 필요로 한다.), 이러한 문제를 막기 위해서 해당 서비스를 제공하는 쪽에서 iframe으로의 호출을 막도록 설정해놓은 것이다.

그렇다면 이 문제가 무엇인지 알아야 향후에 iframe을 사용하게 될 때에도 대처를 할 수 있지 않을까 하는 생각으로 정리해보려고 한다.

## XSS

가장 대표적으로 대두되는 보안 문제는 XSS(Cross Site Scripting)인데, 쉽게 설명하자면 사용자가 input이 가능한 요소에 코드를 심어 보내는 것으로 의도치 않은 기능들을 실행하게 만드는 공격이다. 이는 정작 이 서비스를 제공하는 사람이 아닌, 서비스의 사용자들을 대상으로 하는 문제이므로 피해의 정도가 빠르게 퍼질 수 있다는 점에서 심각한 문제가 된다.

이러한 문제를 해결하기 위해서 같은 도메인을 가지고 있지 않다면 접근할 수 없도록 하는SOP(Same Origin Policy)를 지원하게 되었다. 

