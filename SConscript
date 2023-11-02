
from building import *

cwd     = GetCurrentDir()
src     = Glob('*.c') + Glob('*.cpp')
path    = [cwd]

group = DefineGroup('System_Run_LED', src, depend = ['PKG_USING_SYSTEM_RUN_LED'], CPPPATH = path)

Return('group')
