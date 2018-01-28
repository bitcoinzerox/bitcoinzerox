


# **Hexxcoin [HXX] Core update 2018**
# **Masternodes coming**

Anonymous Zerocoin Protocol:
https://en.wikipedia.org/wiki/Zerocoin

Zerocoin  parameters RSA-2048 from RSA Factoring Challenge
https://en.wikipedia.org/wiki/RSA_Factoring_Challenge

Hexxcoin
----------------
* Coin Suffix: HXX
* Algorithm:lyra2z330
* Algo params: LYRA2(BEGIN(thash), 32, BEGIN(nVersion), 80, BEGIN(nVersion), 80, 2, 330, 256)
* Target Spacing: 150 Seconds
* Retarget: every block
* Confirmation: 6 Blocks
* Maturity: 120 Blocks
* Blocks: ~576 per day
* Total Coins: 9,999,999 HXX
* Min TX Fee: 0.001 HXX
* Block Size: 4MB

Reward table
----------------
* 2 weeks / 1 coin
* 1 week / 3.125 coins
* 1 week / 6.25 coins
* 2 weeks / 12.5 coins
* 6 weeks / 6.25 coins
* 6 weeks / 3.125 coins
* 6 weeks / 1.5625 coins
* And finally, 1 coin reward / block


Net Parameters
----------------
* P2P Port=29100
* RPC Port=29200
* Client core=13.4
* Client name=hexxcoin.qt
* Conf file=hexxcoin.conf

Installation folder
----------------
* Windows: C:\Users\Username\AppData\Roaming\hexxcoin
* Mac:/Library/Application Support/hexxcoin
* Unix: /.hexxcoin




Debian/Ubuntu Linux Daemon Build Instructions
================================================

install dependencies:
Build a node or qt:

if you need a swap memory:
free
dd if=/dev/zero of=/var/swap.img bs=2048 count=1048576
mkswap /var/swap.img
swapon /var/swap.img   
free   


sudo apt-get update
sudo apt-get upgrade

sudo apt-get install git build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils libboost-all-dev

sudo apt-get install software-properties-common
sudo add-apt-repository ppa:bitcoin/bitcoin
sudo apt-get update
sudo apt-get install libdb4.8-dev libdb4.8++-dev

sudo apt-get install libminiupnpc-dev libzmq3-dev
for qt:
sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler libqrencode-dev

git clone https://github.com/hexxcointakeover/4.0.1.2 hexxcoin

cd hexxcoin
for vps:
./autogen.sh
./configure  --without-gui
make -j 4   (-j is optional, number of your cores, -j 4)

for qt:
./autogen.sh
./configure
make -j 4   (-j is optional, number of your cores, -j 4)

cd src
strip hexxcoind
or:
cd src
cd qt
strip hexxcoin-qt

files are:
hexxcoind
hexxcoin-cli

hexxcoin-qt
hexxcoin.conf
data folder:
hexxcoin

port 29100
rpc port 29200

Example hexxcoin.conf Configuration
===================================================

	addnode=node_ip
	rpcallowip=127.0.0.1
	rpcuser=MAKEUPYOUROWNUSERNAME
	rpcpassword=MAKEUPYOUROWNPASSWORD
	server=1

	
	



