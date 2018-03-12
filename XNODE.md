Xnode Instructions and Notes
=============================
 - Version 0.1.7
 - Date: 6 March 2018

Prerequisites
-------------
 - Ubuntu 16.04+
 - Port **29100** is open
 - Libraries to build from hexxcoin source if you want to build it yourself

Step 0. ON VPS: Acquire the binaries
----------------------

Either

<details open>
<summary><strong>Download the prebuilt binaries</strong></summary>
<strong>0.1</strong> Install prebuild client and full chain

	mkdir .hexxcoin
	cd .hexxcoin
	sudo apt-get install unzip
	wget https://github.com/hexxcointakeover/hexxcoin/releases/download/05.03.2018/hexxcoin.zip
	unzip hexxcoin.zip
	cd ..
	wget https://github.com/hexxcointakeover/hexxcoin/releases/download/4.0.2.6/linux-x64.zip
	unzip linux-x64.zip
	
	./hexxcoind -daemon
	./hexxcoin-cli getinfo
</details>

or

<details>
<summary><strong>Build from source</strong></summary>
<strong>0.1.</strong>  Check out from source:

    git clone https://github.com/hexxcointakeover/hexxcoin

<strong>0.2.</strong>  See [README.md](README.md) for instructions on building.
</details>
	

Step 1. ON VPS: Open port 29100 (Optional - only if firewall is running)
----------------------
**1.1.**  Run:

    sudo ufw allow ssh 
    sudo ufw allow 29100
    sudo ufw default allow outgoing
    sudo ufw enable

Step 2. ON LOCAL MACHINE: First run on your Local Wallet
----------------------

<details open>
<summary><strong>If you are using the qt wallet</strong></summary>
<strong>2.0.</strong>  Open the wallet

<strong>2.1.</strong>  Click Help -> Debug window -> Console

<strong>2.2.</strong>  Generate xnodeprivkey:

    xnode genkey

(Store this key)

<strong>2.3.</strong>  Get wallet address:

    getaccountaddress XN1

<strong>2.4.</strong>  Send to received address <strong>exactly 2000 HXX</strong> in <strong>1 transaction</strong>. Wait for 15 confirmations.

<strong>2.5.</strong>  Close the wallet
</details>

<details>
<summary><strong>If you are using the daemon</strong></summary>
<strong>2.0.</strong>  Go to the checked out folder or where you extracted the binaries

    cd hexxcoin/src

<strong>2.1.</strong>  Start daemon:

    ./hexxcoind -daemon -server

<strong>2.2.</strong>  Generate xnodeprivkey:

    ./hexxcoin-cli xnode genkey

(Store this key)

<strong>2.3.</strong>  Get wallet address:

    ./hexxcoin-cli getaccountaddress XN1

<strong>2.4.</strong>  Send to received address <strong>exactly 2000 HXX</strong> in <strong>1 transaction</strong>. Wait for 15 confirmations.

<strong>2.5.</strong>  Stop daemon:

    ./hexxcoin-cli stop
</details>


## For both:

**2.6.**  Create file **xnode.conf** (in **~/.hexxcoin**, **C:\Users\USER\AppData\Roaming\hexxcoin** or **~/Library/Application Support/hexxcoin** depending on your Operating System) containing the following info:
 - LABEL: A one word name you make up to call your node (ex. XN1)
 - IP:PORT: Your xnode VPS's IP, and the port is always 29100.
 - XNODEPRIVKEY: This is the result of your "xnode genkey" from earlier.
 - TRANSACTION HASH: The collateral tx. hash from the 2000 HXX deposit.
 - INDEX: The Index from the transaction hash

To get TRANSACTION HASH, run:

```
./hexxcoin-cli xnode outputs
```
or
```
xnode outputs
```

depending on your wallet/daemon setup.

The output will look like:

    { "d6fd38868bb8f9958e34d5155437d009b72dfd33fc28874c87fd42e51c0f74fdb" : "0", }

Sample of xnode.conf:

    XN1 51.52.53.54:29100 XrxSr3fXpX3dZcU7CoiFuFWqeHYw83r28btCFfIHqf6zkMp1PZ4 d6fd38868bb8f9958e34d5155437d009b72dfd33fc28874c87fd42e51c0f74fdb 0

**2.7.** Lock unspent

As long as the xnode is listed in your xnode.conf file the funds are automatically locked so you don't accidentially spend them.

Step 3. ON VPS: Update config files
----------------------
**3.1.**  Create file **hexxcoin.conf** (in folder **~/.hexxcoin**)

    rpcuser=username
    rpcpassword=password
    rpcallowip=127.0.0.1
    server=1
    maxconnections=24
    xnode=1
    xnodeprivkey=XXXXXXXXXXXXXXXXX  ## Replace with your xnode private key
    externalip=XXX.XXX.XXX.XXX ## Replace with your node external IP


Step 4. ON LOCAL MACHINE: Start the xnode
----------------------

<details open>
<summary><strong>With qt wallet</strong></summary>
<strong>4.1</strong> Start the xnode via your gui wallet in the xnodes tab
</details>

<details>
<summary><strong>With daemon</strong></summary>
<strong>4.1</strong> Start xnode:

    ./hexxcoin-cli xnode start-alias <LABEL>

For example:

    ./hexxcoin-cli xnode start-alias XN1

<strong>4.2</strong>  To check node status:

    ./hexxcoin-cli xnode debug

</details>


If not successfully started, just repeat start command
