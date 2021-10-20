import discord
from discord.ext import tasks, commands
from core.classes import Cog_模組
from datetime import datetime
import json, asyncio, datetime

#設定檔
with open("setting.json",'r',encoding="ansi") as jfile:
    j設定 = json.load(jfile)

#訊息檔
with open("message.json",'r',encoding="ansi") as jfile:
    j訊息 = json.load(jfile)

class 背景作業(Cog_模組):
    def __init__(self, bot):
        self.bot = bot
        self.bg_task.start()

    def cog_unload(self):
        self.bg_task.cancel()

    @tasks.loop(minutes = 1)
    async def bg_task(self):
        try:
            channel = self.bot.get_channel(int(j設定["台v_channel"]))
            await channel.send(datetime.datetime.now().strftime('%Y/%m/%d %H:%M:%S'))
        except discord.DiscordException:
            print("背景作業 失敗")

    @bg_task.before_loop
    async def before_bg_task(self):
        await self.bot.wait_until_ready()

def setup(bot):
    bot.add_cog(背景作業(bot))
