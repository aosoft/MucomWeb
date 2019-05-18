'use strict';

import Module from './mucom88.js';

class MucomProcessor extends AudioWorkletProcessor {
    constructor() {
        super();
    }

    static get parameterDescriptors() {
        return [{
            name: 'kernel',
            defaultValue: null
        }];
    }

    process(inputs, outputs, parameters) {
        const kernel = parameters.kernel;
        kernel.mix();

        const output = outputs[0];
        output[0] = this.kernel.getAudioBufferPtrL();
        output[1] = this.kernel.getAudioBufferPtrR();

        return true;
    }
}

registerProcessor('mucom-processor', MucomProcessor);


