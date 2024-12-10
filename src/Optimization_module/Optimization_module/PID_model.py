

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
        self.u_min=-1e10
        self.u_max=1e10
        self.e=0
        self.e_1=0
    
    def update_parameters(self,parameters):
        self.Ie=0
        self.Ki=parameters["Ki"]
        self.Kp=parameters["Kp"]
        self.Kd=parameters["Kd"]
        self.parameters=parameters

    def __call__(self,X):
        e=X[-1]
        if len(X)>1:
            e_1=X[-2]
            self.Kp_term=self.Kp*e
            self.Ie=self.Ie+self.Ki*e*self.T # + self.Kaw*(self.command_sat_prev - self.command_prev)*self.T
            self.Kd_term=self.Kp*e
            self.Kd_term=self.Kp*(e-e_1)/self.T
            u = min(max(self.u_min,self.Kp_term+self.Ie+self.Kd_term),self.u_max)
        else:
            u=0
        return u
    
    def train(self,X):
        self.e=-(self.ref-X)
        #if len(X)>1:
            #e_1=-(self.ref-X[-2])
        self.Kp_term=self.Kp*self.e
        self.Ie=self.Ie+self.Ki*self.e*self.T # + self.Kaw*(self.command_sat_prev - self.command_prev)*self.T
        self.Kd_term=self.Kp*self.e
        self.Kd_term=self.Kp*(self.e-self.e_1)/self.T
        self.Kd_term=self.Kp*(self.e-self.e_1)/self.T
        u = min(max(self.u_min,self.Kp_term+self.Ie+self.Kd_term),self.u_max)
        #else:
        #    u=float(0)
        return u
    
    def test(self,X):
        self.e=-(self.ref-X)
        #if len(X)>1:
            #e_1=-(self.ref-X[-2])
        self.Kp_term=self.Kp*self.e
        self.Ie=self.Ie+self.Ki*self.e*self.T # + self.Kaw*(self.command_sat_prev - self.command_prev)*self.T
        self.Kd_term=self.Kp*self.e
        self.Kd_term=self.Kp*(self.e-self.e_1)/self.T
        u = min(max(self.u_min,self.Kp_term+self.Ie+self.Kd_term),self.u_max)
        #else:
        #    u=float(0)
        return u
    
    def deploy(self,X):
        self.e=-(self.ref-X)
        #if len(X)>1:
            #e_1=X[-2]
        self.Kp_term=self.Kp*self.e
        self.Ie=self.Ie+self.Ki*self.e*self.T # + self.Kaw*(self.command_sat_prev - self.command_prev)*self.T
        self.Kd_term=self.Kp*self.e
        self.Kd_term=self.Kp*(self.e-self.e_1)/self.T
        u = self.Kp_term+self.Ie+self.Kd_term
        #else:
        #    u=float(0)
        return u
