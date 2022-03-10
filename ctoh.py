#!/usr/bin/python
#from pathlib import Path
import sys
import os
import re
if (len(sys.argv)<2):
    print("ctoh.py filename #filename is not present")
    sys.exit()
def comment_remover(text):
    def replacer(match):
        s = match.group(0)
        if s.startswith('/'):
            return " " # note: a space and not an empty string
        else:
            return s
    pattern = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE
    )
    return re.sub(pattern, replacer, text)

def tr(fname):
    print("fname is: ",fname)
    is_src_file = False;
    if(fname.endswith(".cpp")):
        hpp = fname.replace(".cpp","_h.cpp")
        is_src_file = True
    if(fname.endswith(".hpp")):
        hpp = fname.replace(".hpp","_h.hpp")
        is_src_file = True
    if(fname.endswith(".c")):
        hpp = fname.replace(".c","_h.c")
        is_src_file = True
    if(fname.endswith(".h")):
        hpp = fname.replace(".h","_h.h")
        is_src_file = True
    ftekst = ''
    if(is_src_file):
        with open(fname, 'r') as file:
            ftekst = file.read()#.replace('\n', '')
        ftekst = comment_remover(ftekst)
        ftekst = "".join([s for s in ftekst.splitlines(True) if s.strip()])
        ftekst = re.sub('\s+float\s+',' cplong ',ftekst)
        ftekst = re.sub('\s+double\s+',' cplong ',ftekst)
        ftekst = re.sub('\s+([0-9]*\.[0-9]*)f?\s*',r""" cplong("\1") """,ftekst)
        #print("ftekst is :")
        #print("###########")
        ftekst = "#include <cplong.h>" + os.linesep + ftekst
        #print("###########")
        #print(ftekst)
        with open(hpp, 'w') as file:
            file.write(ftekst)
        print("converted float/double to cplong in file: " + hpp)

for i in range(1,len(sys.argv)):
    tr(sys.argv[i])
