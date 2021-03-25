#阿帕比阅读爬虫
import requests

i=1

while i <= 166:
    api = "http://cebxol.apabiedu.com/"+"api/getservice?orgid=jnt&ObjId=ISBN2002-11-15-lj%5CK.149.ft.CEBX.1&UserName=%E6%9D%A5%E8%87%AA%2B%E6%B5%8E%E5%8D%97%E5%B8%82%E5%9B%BE%E4%B9%A6%E9%A6%86%2B%E7%9A%84%E7%94%A8%E6%88%B7&MetaId=ISBN2002-11-15-lj%5CK.149&cult=CN&dbsource=dlib&Time=2021/3/25 8:25:19&Sign=53343BEF554D99718729B2EEF455D636&Rights=1-0_00&width=700&height=1100&page={}&ServiceType=imagepage".format(str(i))
    try:
        res = requests.get(api)
        print(res.status_code)
        if res.status_code !=200:
            continue
    except:
        continue
    with open("{}.png".format(str(i)),"wb")as f:
        f.write(res.content)
    i = i+1
