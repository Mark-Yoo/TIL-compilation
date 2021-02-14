# <RecoilRoot ...props />

atom이 값을 갖는 컨텍스트를 제공합니다. Recoil hooks를 사용하는 컴포넌트의 조상이어야합니다. 여러 root가 공존할 수 있습니다; atom은 각각의 root 내에서 고유한 값을 갖습니다. 만약 중첩되어있다면 가장 안쪽의 root는 바깥쪽의 root를 완전히 마스킹합니다.