price = int(input('가격을 입력해주세요.'))
marketing_agreement = input('마케팅 이용 약관에 동의하십니까? (Y/N)')

if marketing_agreement == 'y' or marketing_agreement == 'Y':
    print('약관에 동의하셨습니다.')
    if price > 50000:
        print('50000원이 초과되는 상품은 추가적으로 검증이 필요합니다.')
    elif price <= 0:
        print('가격은 음수, 0이 될 수 없습니다.')
    else:
        print('등록이 정상적으로 완료되었습니다.')
elif marketing_agreement == 'n' or marketing_agreement == 'N':
    print('약관 동의에 거부하셨습니다. 종료합니다.')
