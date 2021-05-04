map = "#############O   ##  # #####       ##     #  @###      #   ###      #  ##  #       ##    #     ###  #  #   ##   # #    ##  #       #############\x00"
count = 0
for i in map:
    print(i,end='')
    count += 1
    if count == 12:
        count = 0
        print()
