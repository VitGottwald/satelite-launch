import * as React from 'react';
import TSPayload from './TSPayload';
import TSRocket from './TSRocket';
import TSFire from './TSFire';

const TSFalcon9 = ({className}: {className: string}) => (
  <div className={`rocket ${className}`}>
    <TSPayload />
    <TSRocket />
    <TSFire />
  </div>
);

export default TSFalcon9;
