import csv

variant = 'f301'

keyChipPin = 'Chip pin'
keyIndex = 'kod#'
keyTimer = 'Timer'
keyChannel = 'TimChan'
keyTimerAF = 'AF0'
keyADC = 'ADC'
keyADCChannel = 'ADCChan'

PIN_MAP = variant + '/PIN_MAP.csv'
TIMER_MAP = variant + '/TIMER_MAP.csv'

print('\n>>> variant.h >>>\n')
print('\n// >>> Autogenerated by '+__file__+' >>>\n')

with open(PIN_MAP, 'rb') as csvfile:
  reader = csv.DictReader(csvfile, delimiter=',', quotechar='"')
  for line in reader:
    print('extern const uint8_t '+line[keyChipPin]+';')

print('\n'),

with open(TIMER_MAP, 'rb') as csvfile:
  reader = csv.reader(csvfile, delimiter=',', quotechar='"')
  for line in reader:
    for tim in line[1:]:
      if tim != '':
        print('extern const uint8_t TIMER'+tim+';')

print('\n// <<< Autogenerated by '+__file__+' <<<\n')


print('\n>>> variant.cpp >>>\n')
print('\n// >>> Autogenerated by '+__file__+' >>>\n')

with open(PIN_MAP, 'rb') as csvfile:
  reader = csv.DictReader(csvfile, delimiter=',', quotechar='"')
  for line in reader:
    print('const uint8_t '+line[keyChipPin]+' = '+line[keyIndex]+';')

print('\n'),

print('PinInfo PIN_MAP[] = {')
with open(PIN_MAP, 'rb') as csvfile:
  reader = csv.DictReader(csvfile, delimiter=',', quotechar='"')
  for line in reader:
    # GPIOx, PinSourcex
    print('  {GPIO'+line[keyChipPin][1]+', '+line[keyChipPin][2:]+','),
    # ADC channel
    if line[keyADCChannel] != '':
      print(line[keyADCChannel]+','),
    else:
      print('NOT_SET,'),
    # Timer AF
    if line[keyTimerAF] != '':
      print(line[keyTimerAF]+','),
    else:
      print('NOT_SET,'),
    # Timer
    if line[keyTimer] != '':
      print('TIMER'+line[keyTimer]+','),
    else:
      print('NOT_SET,'),
    # Timer channel
    if line[keyChannel] != '':
      print(line[keyChannel]+','),
    else:
      print('NOT_SET,'),
    # adcConvIndex
    print('NOT_SET,'),
    # ioConfigtimer
    print('NOT_SET},')
print('};')

print('\n'),

# Timer declaration
with open(TIMER_MAP, 'rb') as csvfile:
  reader = csv.reader(csvfile, delimiter=',', quotechar='"')
  i=0
  for line in reader:
    for tim in line[1:]:
      if tim != '':
        print('const uint8_t TIMER'+tim+' = '+str(i)+';')
        i+=1

print('\n'),

# Timer channel data (run-time config)
with open(TIMER_MAP, 'rb') as csvfile:
  reader = csv.reader(csvfile, delimiter=',', quotechar='"')
  for line in reader:
    for tim in line[1:]:
      numChan = line[0][0]
      if tim != '' and int(numChan) > 0:
        print('TimerChannelData timer'+tim+'ch['+numChan+'] = {')
        for i in range(int(numChan)-1):
          print('  {0, false, 0, 0, 0, 0},')
        print('  {0, false, 0, 0, 0, 0}')
        print('};')

print('\n'),

# Timer hardware constants
print('TimerInfo TIMER_MAP[] = {')
with open(TIMER_MAP, 'rb') as csvfile:
  reader = csv.reader(csvfile, delimiter=',', quotechar='"')
  for line in reader:
    for tim in line[1:]:
      if tim != '':
        print('  {TIM'+tim+', TIM'+tim+'_IRQn, 1000, 0,'),
        if int(line[0][0]) > 1:
          print('timer'+tim+'ch},')
        else:
          print('(TimerChannelData *)0},')
print('  // ^^^ Look up IRQn names from CMSIS device header ^^^')
print('};')

print('\n// <<< Autogenerated by '+__file__+' <<<\n')

