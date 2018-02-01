




static map<int, uint256> mapPoWHash;

const char *precomputedHash[0] =
{
		""	
};

void buildMapPoWHash() {
        mapPoWHash.insert(make_pair(i, uint256S(precomputedHash[i])));
    }
};
 