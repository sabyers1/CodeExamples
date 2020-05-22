class Platformer:

    def __init__(self, n, x):
        """
        :param n: (int) The initial number of tiles.
        :param x: (int) The initial position of the character.
        """
        self.m_tiles = n
        self.m_pos = x
        #need map of tiles and whether they are present
        self.m_tilemap = [1 for i in range(n)]
        
    def jump_left(self):
        # Previous position disappears
        curpos = self.m_pos
        moves = 2
        while (curpos>-1 and moves>0):
            curpos -= 1
            if self.m_tilemap[curpos] != 0:
                moves -= 1
        self.m_tilemap[self.m_pos]= 0  #tile disappears
        newpos = curpos
        if newpos < 0:
            newpos = 0
        self.m_pos = newpos

    def jump_right(self):
 # Previous position disappears
        curpos = self.m_pos
        moves = 2
        while (curpos<self.m_tiles-1 and moves>0):
            curpos += 1
            if self.m_tilemap[curpos] != 0:
                moves -= 1
        self.m_tilemap[self.m_pos]= 0  #tile disappears
        newpos = curpos
        if newpos > self.m_tiles-1:
            newpos = self.m_tiles-1
        self.m_pos = newpos

    def position(self):
        """
        :returns: (int) The position of the character.
        """
        return self.m_pos

    def show(self):       
        for idx,val in enumerate(self.m_tilemap):
            print("(" if self.m_pos == idx else " ","{}".format(val),")" if self.m_pos == idx else " ",end="")

platformer = Platformer(6, 3)
platformer.show()
print(platformer.position()) # should print 3
platformer.jump_left()
platformer.show()
print(platformer.position()) # should print 1
platformer.jump_right()
platformer.show()
print(platformer.position()) # should print 4