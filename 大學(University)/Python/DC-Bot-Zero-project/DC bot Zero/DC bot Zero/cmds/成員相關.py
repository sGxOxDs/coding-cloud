import discord
from discord.ext import commands
from core.classes import Cog_模組
import json, random

#設定檔
with open("setting.json",'r',encoding="ansi") as jfile:
    j設定 = json.load(jfile)

#訊息檔
with open("message.json",'r',encoding="ansi") as jfile:
    j訊息 = json.load(jfile)

class 成員相關(Cog_模組):

    #成員加入
    @commands.Cog.listener()
    async def on_member_join(self, member):
        channel = self.bot.get_channel(int(j設定["join_channel"]))
        random_join = random.choice(j訊息["join_message"])
        await channel.send(f"{member.mention} " + random_join)
        print(f"{member} join!")

    #成員離開
    @commands.Cog.listener()
    async def on_member_remove(member):
        channel = self.bot.get_channel(int(j設定["leave_channel"]))
        random_leave = random.choice(j訊息["leave_message"])
        await channel.send(f"{member.mention} " + random_leave)
        print(f"{member} leave...")

def setup(bot):
    bot.add_cog(成員相關(bot))
