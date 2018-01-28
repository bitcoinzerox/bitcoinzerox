




static map<int, uint256> mapPoWHash;

const char *precomputedHash[11] =
{
		""	
        "322bad477efb4b33fa4b1f0b2861eaf543c61068da9898a95062fdb02ada486f",
        "edcce7a202f07ea4ea2ca1883b7d70c6f44fa53f5f88ba62abe8f94284a1d7b3",
        "4affde0cc885b35b8eeb72f89506ae297cc7d3f98453df91a3605b446acaad17",
        "86d0650c320497c1830e6566c0678deb893ad72fc95aa29d8279c4d3d1d80907",
		"b79a780518dadcd4642bace9b60c170689a81deec15e2280a9e882b91dbfb827",
        "0cae7e8b0874f32962856da5349dbb097ec03b4cf3a1aae155d2e5f7932f1ca8",
        "74a52e402c897a2f3a02fe2e465bdf9cee64a898abef19af06994fcbc4add3e6",
        "57d3243411382be2330c5a172cc615cf9dfe6ba89d819d39142351cd2865493f",
        "51491f52bcb4493815a72f3301972461d8a26e45d21a586e31665f8e65e91fb2",
        "de29022b4a5c814ef42a314f5d370d9136ff1a282071f430b61d0afd65d93f67",
		"9b2d759d02231982f602110ddacf99d4f3bdae3055fe5ae6801071f42990fdeb",
};

void buildMapPoWHash() {
    for (int i=1; i<10; i++) {
        mapPoWHash.insert(make_pair(i, uint256S(precomputedHash[i])));
    }
};
 