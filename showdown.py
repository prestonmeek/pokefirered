def createField(key: str, value: str, format: bool = True) -> str:
    if format: 
        value = value.replace('[', '').replace(']', '')             # remove any brackets (namely in hidden power)
        value = value.replace('.', '')                              # remove any periods (namely in MR. MIME)
        value = value.replace(' (M)', '').replace(' (F)', '')       # removes any male/female indicators
        value = value.replace(' ', '_').replace('-', '_').upper()   # replace spaces and dashes with underscores; capitalize

    return "\t.{key} = {value},\n".format(key=key, value=value)

def parsePokemon(inp):
    if not inp: return ''

    res = """{\n"""

    # assumes you want max ivs
    res += createField('iv', '255')

    lines = inp.splitlines()

    # line 1: name of pokemon @ held item
    species, item = lines[0].split(' @ ')
    res += createField('species', 'species ' + species.strip())
    res += createField('heldItem', 'item ' + item.strip())

    # while line 1 is always the pokemon's name, the other lines can be a bit out of order
    # because of this, we just handle cases based on what the line starts with

    # create default values
    level = 100
    moves = []

    for line in lines[1:]:
        line = line.strip()

        # extract the level
        if line.startswith('Level'):
            level = line.split(' ')[1]
        # move
        elif line.startswith('- '):
            moves.append('move ' + line[2:])
        # if line is empty, we have finished the current pokemon
        elif not line:
            break
        
    # add the level field
    res += createField('lvl', level, False)

    # convert the moves array to a string and add it
    movesString = '{' + ','.join(moves) + '}'
    res += createField('moves', movesString)

    res += '},\n'

    return res

if __name__ == '__main__':
    print('Please paste your Showdown export below.')
    print('Press enter after pasting, then press ctrl-C.\n')

    contents = []

    while True:
        try:
            line = input()
        except KeyboardInterrupt:
            break

        contents.append(line)

    # take each line, join them all, then split by each pokemon
    contents = '\n'.join(contents).split('\n\n')

    res = ''

    for pokemon in contents:
        res += parsePokemon(pokemon)

    print(res)
