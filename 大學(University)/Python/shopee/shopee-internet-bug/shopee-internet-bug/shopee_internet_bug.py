import requests
import urllib
import json
import time


def main():
    keyword = "手機保護殼"
    headers = {
        "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/88.0.4324.150 Safari/537.36 Edg/88.0.705.68",
        "x-api-source": "pc",
        "referer": f"https://shopee.tw/search?keyword={urllib.parse.quote(keyword)}"
    }

    s = requests.Session()
    url = "https://shopee.tw/api/v4/search/product_labels"
    r = s.get(url, headers=headers)

    base_url = "https://shopee.tw/api/v2/search_items/"
    query = f"by=relevancy&keyword={keyword}&limit=50&newest=0&order=desc&page_type=search&version=2"
    url = base_url + '?' + query
    r = s.get(url, headers=headers)
    if r.status_code == requests.codes.ok:
        data = r.json()
        with open('shopee.json', 'w', encoding='utf-8') as f:
            f.write(r.text)
    items = data["items"]
    
    for item in items:
        info = get_info(item)
        for list in info:
            print(list + ":" + f"{info[list]}")
        print("-------------")

def get_info(item):

    url = "https://shopee.tw/" + "None" +"-i." + f"{item['shopid']}" + "." + f"{item['itemid']}"

    time_stamp = item["ctime"] # 設定timeStamp
    struct_time = time.localtime(time_stamp) # 轉成時間元組
    timeString = time.strftime("%Y-%m-%d %H:%M:%S", struct_time) # 轉成字串

    price = item["price"]/100000
    info = {
        "賣場ID":item["shopid"],
        "商品名稱":item["name"],
        "商品ID":item["itemid"],
        "價格":price,
        "上架時間":timeString,
        "已售出數量":item["historical_sold"],
        "評價數":item["item_rating"]["rating_count"][0],
        "URL":url
    }
    return info

if __name__ == "__main__":
    main()