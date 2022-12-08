history = []

for i in range(5):
    history.append(input('시청한 영상은?'))
print('지금까지 시청한 영상은', history)

if '다이어트' in history:
    print('다이어트 영상을 좋아하시면 홈트 영상도 추천!')
if '뉴스' in history:
    print('뉴스 영상을 좋아하시면 속보도 추천!')