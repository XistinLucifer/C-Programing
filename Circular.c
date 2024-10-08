'use strict';

import * as WEVector from 'WEVector';

var bars = [];
var baseOrigin;

let audioData = engine.registerAudioBuffers(64);

/**
 * @param {Boolean} value (for property 'visible')
 */
export function update() {

    //var origin = baseOrigin.copy();
    var scale = new Vec3(5);

    for (var i = 0; i < 64; ++i) {
        let amt = audioData.average[i];
        let bar = bars[i];

        scale.y = amt * 50;
        //origin.x += 20;
        bar.scale = scale;
        //bar.origin = origin;
    }

}

/**
 * @param {Boolean} value (for property 'visible')
 */
export function init() {
    let center = thisLayer.origin;
	bars.push(thisLayer);
    let thisIndex = thisScene.getLayerIndex(thisLayer);
    for (var i = 1; i < 64; ++i) {
        let newBar = thisScene.createLayer('models/bar.json');
        thisScene.sortLayer(newBar, thisIndex);
	newBar.parallaxDepth = new Vec2(0,0);/*this sets the parallax strength of the automatic bars to not move*/
        bars.push(newBar);
    }

    for (var i = 0; i < 64; ++i) {
        let angle = 360 * (i / 64);
        let direction = new Vec3(WEVector.angleVector2(angle)).multiply(350); /* circle radius*/
        let bar = bars[i];
        bar.origin = center.add(direction);
        bar.angles = new Vec3(0, 0, angle + 90);
    }

}