#-*- coding: utf-8 -*-
#-*- coidng: euc-kr -*-

from django.shortcuts import render
from django.http import HttpResponse
from .models import Candidate

# 한글사용
import sys
reload(sys)
sys.setdefaultencoding('utf-8')

def index(request):
    candidates = Candidate.objects.all()
    return render(request, 'APP/index.html')
