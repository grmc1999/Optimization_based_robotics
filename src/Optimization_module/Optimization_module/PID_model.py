

class basic_PID_model(object):
    def __init__(self,Ki,Kp,Kd,T):
        self.Ki=Ki
        self.Kp=Kp
        self.Kd=Kd
        self.parameters={
            "Kp":self.Kp,
            "Ki":self.Ki,
            "Kd":self.Kd,
        }
        self.T=T
        self.Ie=0

        self.ref=0
    
    def update_parameters(self,parameters):
        self.Ki=parameters["Ki"]
        self.Kp=parameters["Kp"]
        self.Kd=parameters["Kd"]
        self.parameters=parameters

    def __call__(self,X):
        e=X[-1]
        print(len(X))
        if len(X)>1:
            e_1=X[-2]
            self.Kp_term=self.Kp*e
            self.Ie=self.Ki*self.Ie+e*self.T # + self.Kaw*(self.command_sat_prev - self.command_prev)*self.T
            self.Kd_term=self.Kp*e
            self.Kd_term=self.Kp*(e-e_1)/self.T
            u = self.Kp_term+self.Ie+self.Kd_term
        else:
            u=0
        return u
    
    def train(self,X):
        e=abs(self.ref-X[-1])
        print(len(X))
        #self.Ki=0
        #self.Kd=0
        if len(X)>1:
            e_1=abs(self.ref-X[-2])
            self.Kp_term=self.Kp*e
            self.Ie=self.Ki*self.Ie+e*self.T # + self.Kaw*(self.command_sat_prev - self.command_prev)*self.T
            self.Kd_term=self.Kp*e
            self.Kd_term=self.Kp*(e-e_1)/self.T
            u = self.Kp_term+self.Ie+self.Kd_term
        else:
            u=float(0)
        return u
    
    def test(self,X):
        e=abs(self.ref-X[-1])
        print(len(X))
        if len(X)>1:
            e_1=abs(self.ref-X[-2])
            self.Kp_term=self.Kp*e
            self.Ie=self.Ki*self.Ie+e*self.T # + self.Kaw*(self.command_sat_prev - self.command_prev)*self.T
            self.Kd_term=self.Kp*e
            self.Kd_term=self.Kp*(e-e_1)/self.T
            u = self.Kp_term+self.Ie+self.Kd_term
        else:
            u=float(0)
        return u
    
    def deploy(self,X):
        e=abs(self.ref-X[-1])
        print(len(X))
        if len(X)>1:
            e_1=X[-2]
            self.Kp_term=self.Kp*e
            self.Ie=self.Ki*self.Ie+e*self.T # + self.Kaw*(self.command_sat_prev - self.command_prev)*self.T
            self.Kd_term=self.Kp*e
            self.Kd_term=self.Kp*(e-e_1)/self.T
            u = self.Kp_term+self.Ie+self.Kd_term
        else:
            u=float(0)
        return u
