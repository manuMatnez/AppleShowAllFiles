/*
 This file is part of AppleShowAllFiles.
 AppleShowAllFiles is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 AppleShowAllFiles is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with AppleShowAllFiles.  If not, see <http://www.gnu.org/licenses/>.
 */

//
//  ViewController.swift
//  AppleShowAllFiles
//
//  Created by Manuel Martinez Martin on 19/2/17.
//  Copyright © 2017 Manuel Martinez Martin. All rights reserved.
//

import Cocoa

class ViewController: NSViewController {

    @IBOutlet var status: NSTextField!
    @IBOutlet var cambiar: NSButton!
    
    var statusColor: NSColor!
    
    // Gets the current hidden files color (Green/Red).
    func getColors() {
        switch(fileStatus()) {
        case true:
            statusColor = NSColor(
                calibratedHue: 137/360,
                saturation: 0.99,
                brightness: 0.60,
                alpha: 1)
            break;
        case false:
            statusColor = NSColor(
                calibratedHue: 359/360,
                saturation: 0.99,
                brightness: 0.70,
                alpha: 1)
            break;
        }
    }
    
    // Button Change (Show/Hide).
    func buttonText() -> String {
        switch(fileStatus()) {
        case true:
            return NSLocalizedString("HIDE",comment:"HIDE FILES")
        case false:
            return NSLocalizedString("SHOW",comment:"SHOW FILES")
        }
    }
    
    // Gets the current hidden files status.
    func onChangedStatus() {
        getColors()
        switch(fileStatus()) {
        case true:
            self.status.stringValue = NSLocalizedString("ENABLED",comment:"ENABLED HF")
            break;
        case false:
            self.status.stringValue = NSLocalizedString("DISABLED",comment:"DISABLED HF")
            break;
        }
        self.status.sizeToFit()
        self.status.textColor = statusColor
        self.cambiar.title = "\(buttonText())"
        self.cambiar.sizeToFit()
    }
    
    // Do any additional setup after loading the view.
    override func viewDidLoad() {
        super.viewDidLoad()
        onChangedStatus()
    }

    // Update the view, if already loaded.
    override var representedObject: Any? {
        didSet {}
    }
    
    @IBAction func showAllFiles(_ sender: Any) {
        let result = changeStatus()
        print(result)
        onChangedStatus()
    }

}

