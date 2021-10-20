
import requests
from pprint import pprint
from datetime import datetime
import json
#https://www.youtube.com/channel/UCFEd5V7VcxBPPcuMGpmvkQA/videos?view=2&live_view=503 之前直播
#https://www.youtube.com/channel/UCFEd5V7VcxBPPcuMGpmvkQA/videos?view=2&live_view=501 直播中
#https://www.youtube.com/channel/UCFEd5V7VcxBPPcuMGpmvkQA/videos?view=2&live_view=502 等待直播
YOUTUBE_API_KEY = "AIzaSyDrioA9DyAqDpf40K-D3cHYzWa0bSItxIE"


def main():
    youtube_channel_id = "UCFEd5V7VcxBPPcuMGpmvkQA"

    youtube_spider = YoutubeSpider(YOUTUBE_API_KEY)
    data = youtube_spider.get_html_to_json("")
    
    print(data)

    

class YoutubeSpider():
    def __init__(self, api_key):
        self.base_url = "https://www.youtube.com/channel/UCFEd5V7VcxBPPcuMGpmvkQA/videos?view=2&live_view=503"
        self.api_key = api_key

    def get_html_to_json(self, path):
        """組合 URL 後 GET 網頁並轉換成 JSON"""
        api_url = f"{self.base_url}"
        r = requests.get(api_url)
        if r.status_code == requests.codes.ok:
            data = r.json()
        else:
            data = None
        return data




