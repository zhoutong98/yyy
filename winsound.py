# -*-conding:utf8 -*-
import winsound
winsound.PlaySound("试探 .wav", winsound.SND_FILENAME)

import pygame
pygame.mixer.init()
print(u"播放音乐")
a = pygame.mixer.music.load("试探 .wav")