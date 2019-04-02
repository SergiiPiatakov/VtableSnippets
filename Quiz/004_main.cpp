enum USB_CLASS
{
    UNSPECIFIED  = 0
  , AUDIO        = (1 << 0)
  , MASS_STORAGE = (1 << 1)
};

enum BT_PROFILE
{
    DIP          = 0        // Device ID profile.
  , A2DP         = (1 << 0) // Advanced audio distribution profile.
  , HFP          = (1 << 1) // Hands free profile.
  , MAP          = (1 << 2) // Message access profile.
};


// USB gadget.
struct Usb
{
    virtual USB_CLASS UsbCapability () const {return UNSPECIFIED;}
    int id {42};
};

// Bluetooth gadget.
struct Bt
{
    virtual BT_PROFILE BtCapability () const {return DIP;}
    int address {-1};
};

// Device with multiple interfaces.
struct Player : Usb, Bt
{
    USB_CLASS UsbCapability () const override
    {
        return static_cast <USB_CLASS> (AUDIO | MASS_STORAGE);
    }
    BT_PROFILE BtCapability () const override
    {
        return A2DP;
    }
    int tracks {0};
};


bool TestPlayer (Player * /*device*/)
{
    return true;
}

bool TestUsb (Usb * device)
{
    return device->UsbCapability () != UNSPECIFIED;
}

bool TestBt (Bt * device)
{
    return device->BtCapability ();
}


int main ()
{
    Usb    usb;
    Bt     bt;
    Player player;

    TestPlayer  (& player);
    TestUsb     (& player);
    TestBt      (& player);
    TestUsb     (& usb);
    TestBt      (& bt);

    return 0;
}
