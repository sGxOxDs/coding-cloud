import discord
from discord.ext import commands

#Cog 一種模塊化的程式架構 可實現程式在線修訂
class Cog_模組(commands.Cog):
    def __init__(self, bot):
        self.bot = bot
